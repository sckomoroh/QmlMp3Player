#ifndef _SongInfoReaderThread_H_
#define _SongInfoReaderThread_H_

#include <QList>
#include <QThread>

class SongInfoReaderThread final : public QThread {
    Q_OBJECT
private:
    struct SongInfo {
        quint64 id;
        QString path;
    };

private:
    QList<SongInfo> _items;

public:
    using QThread::QThread;

public:
    void addSongItem(quint64 id, const QString& path);

signals:
    void infoObtained(quint64 id, QString title, QString artist, quint64 length, quint64 bitrate);

private:
    void run() override;
};

#endif  // _SongInfoReaderThread_H_
