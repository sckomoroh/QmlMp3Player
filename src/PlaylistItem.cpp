#include "PlaylistItem.h"

PlaylistItem::PlaylistItem(quint64 id, const QString& title, const QString& path, QObject* parent)
    : QObject{parent}
    , _id{id}
    , _path{path}
    , _title{title}
    , _artist{"N/A"}
    , _length{0}
    , _bitrate{0}
{
}

quint64 PlaylistItem::id() const { return _id; }

const QString& PlaylistItem::path() const { return _path; }

const QString& PlaylistItem::title() const { return _title; }

const QString& PlaylistItem::artist() const { return _artist; }

QString PlaylistItem::length() const
{
    quint32 mins = _length / 60;
    quint32 secs = _length % 60;
    return QString("%1:%2").arg(mins).arg(secs, 2, 10, QChar('0'));
}

QString PlaylistItem::bitrate() const { return QString("%1kbps").arg(_bitrate); }

void PlaylistItem::setTitle(const QString& title)
{
    _title = title;
    emit titleChanged(_title);
}

void PlaylistItem::setArtist(const QString& artist)
{
    _artist = artist;
    emit artistChanged(_artist);
}

void PlaylistItem::setLength(qint64 length)
{
    _length = length;
    emit lengthChanged(this->length());
}

void PlaylistItem::setBitrate(qint64 bitrate)
{
    _bitrate = bitrate;
    emit bitrateChanged(this->bitrate());
}
