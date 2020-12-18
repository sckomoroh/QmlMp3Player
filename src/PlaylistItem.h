#ifndef _PlaylistItem_H_
#define _PlaylistItem_H_

#include <QObject>
#include <QString>

class PlaylistItem final : public QObject {
    Q_OBJECT
private:
    quint64 _id;
    QString _path;
    QString _title;
    QString _artist;
    qint64 _length;
    qint64 _bitrate;

public:
    PlaylistItem(quint64 id, const QString& title, const QString& path, QObject* parent = nullptr);

public:
    Q_PROPERTY(QString source READ path CONSTANT);
    Q_PROPERTY(QString title READ title NOTIFY titleChanged);
    Q_PROPERTY(QString artist READ artist NOTIFY artistChanged);
    Q_PROPERTY(QString length READ length NOTIFY lengthChanged);
    Q_PROPERTY(QString bitrate READ bitrate NOTIFY bitrateChanged);

public:
    quint64 id() const;
    const QString& path() const;
    const QString& title() const;
    const QString& artist() const;
    QString length() const;
    QString bitrate() const;

    void setTitle(const QString& title);
    void setArtist(const QString& artist);
    void setLength(qint64 length);
    void setBitrate(qint64 bitrate);

signals:
    void titleChanged(QString title);
    void artistChanged(QString artist);
    void lengthChanged(QString length);
    void bitrateChanged(QString bitrate);
};

#endif  // _PlaylistItem_H_
