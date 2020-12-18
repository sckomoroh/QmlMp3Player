#ifndef _PlaylistModel_H_
#define _PlaylistModel_H_

#include <QAbstractListModel>
#include <QList>
#include <QObject>
#include <QSharedPointer>

#include "PlaylistItem.h"
#include "SongInfoReaderThread.h"

class PlaylistModel : public QAbstractListModel {
    Q_OBJECT
private:
    quint64 _id;
    QList<QSharedPointer<PlaylistItem>> _items;
    SongInfoReaderThread* _songInfoReaderThread;

public:
    PlaylistModel(QObject* parent = nullptr);

public:  // QAbstractListModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void sourceChanged(quint64 index);
    void itemAdded(QString source);

public slots:
    void openFolder(const QString& folder);
    void clearPlaylist();
    void addItem(const QString& path);
    void removeItem(quint64 id);

    void onItemDoubleClicked(quint64 index);

private slots:
    void onInfoObtained(quint64 id, QString title, QString artist, quint64 length, quint64 bitrate);

public:
    enum { Item = Qt::UserRole + 1 };
};

#endif  // _PlaylistModel_H_
