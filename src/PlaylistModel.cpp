#include "PlaylistModel.h"

#include <QDebug>
#include <QDirIterator>
#include <QUrl>

#include <algorithm>

PlaylistModel::PlaylistModel(QObject* parent)
    : QAbstractListModel{parent}
    , _songInfoReaderThread{new SongInfoReaderThread{this}}
{
    connect(_songInfoReaderThread,
        &SongInfoReaderThread::infoObtained,
        this,
        &PlaylistModel::onInfoObtained);
}

int PlaylistModel::rowCount(const QModelIndex&) const { return _items.count(); }

QVariant PlaylistModel::data(const QModelIndex& index, int role) const
{
    QVariant value;

    do {
        if (!index.isValid()) {
            break;
        }

        auto item = _items.at(index.row());
        if (!item) {
            break;
        }

        if (role == Item) {
            value.setValue<PlaylistItem*>(item.get());
        }
    } while (false);

    return value;
}

QHash<int, QByteArray> PlaylistModel::roleNames() const { return {{Item, "item"}}; }

void PlaylistModel::openFolder(const QString& folderUrl)
{
    beginResetModel();

    _items.clear();
    _id = 1;

    auto folder = QUrl(folderUrl).path();
    QDirIterator dirIterator(folder, {"*.mp3"});
    while (dirIterator.hasNext()) {
        auto item = dirIterator.next();
        _songInfoReaderThread->addSongItem(_id, item);
        _items.append(QSharedPointer<PlaylistItem>::create(_id++, item, item));
        emit itemAdded("file://" + item);
    }

    _songInfoReaderThread->start();

    endResetModel();
}

void PlaylistModel::clearPlaylist()
{
    beginResetModel();

    _id = 0;
    _items.clear();

    endResetModel();
}

void PlaylistModel::addItem(const QString& path)
{
    beginResetModel();

    auto item = QSharedPointer<PlaylistItem>::create(_id++, path, path);

    endResetModel();
}

void PlaylistModel::removeItem(quint64 id)
{
    beginResetModel();

    auto iter = std::find_if(_items.begin(),
        _items.end(),
        [id](const QSharedPointer<PlaylistItem>& item) { return item && item->id() == id; });

    if (iter != _items.end()) {
        _items.erase(iter);
    }

    endResetModel();
}

void PlaylistModel::onItemDoubleClicked(quint64 index) { emit sourceChanged(index); }

void PlaylistModel::onInfoObtained(quint64 id,
    QString title,
    QString artist,
    quint64 length,
    quint64 bitrate)
{
    do {
        auto iter = std::find_if(_items.begin(),
            _items.end(),
            [id](const QSharedPointer<PlaylistItem>& item) { return item && item->id() == id; });

        if (iter == _items.end()) {
            break;
        }

        auto item = *iter;
        if (!item) {
            break;
        }

        item->setArtist(artist);
        item->setTitle(title);
        item->setLength(length);
        item->setBitrate(bitrate);
    } while (false);
}
