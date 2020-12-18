#include "SongInfoReaderThread.h"

#include <QFileInfo>

#include <fileref.h>

void SongInfoReaderThread::addSongItem(quint64 id, const QString& path)
{
    _items.append({id, path});
}

void SongInfoReaderThread::run()
{
    for (auto&& item : _items) {
        do {
            TagLib::FileRef fileRef{item.path.toStdString().c_str()};
            if (fileRef.isNull()) {
                break;
            }

            auto tag = fileRef.tag();
            if (!tag) {
                break;
            }

            auto artist = QString{tag->artist().toCString()};
            auto title = QString{tag->title().toCString()};
            if (title.isEmpty()) {
                QFileInfo fileInfo{item.path};
                title = fileInfo.fileName();
            }

            quint64 length = 0, bitrate = 0;

            auto properties = fileRef.audioProperties();
            if (properties) {
                length = properties->lengthInSeconds();
                bitrate = properties->bitrate();
            }

            emit infoObtained(item.id, title, artist, length, bitrate);

        } while (false);
    }

    _items.clear();
}
