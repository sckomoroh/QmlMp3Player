#include "ControlModel.h"

#include <QDebug>
#include <QMediaPlaylist>

ControlModel::ControlModel(QObject* parent)
    : QObject{parent}
    , _player{new QMediaPlayer{this}}
    , _playlist{new QMediaPlaylist{_player}}
{
    _player->setPlaylist(_playlist);
    _playlist->setPlaybackMode(QMediaPlaylist::Loop);
}

void ControlModel::onPositionChanged(double value)
{
    _player->setPosition(_player->duration() * value);
}

void ControlModel::onVolumeChanged(double value) { _player->setVolume(value); }

void ControlModel::onBackwardClicked()
{
    _playlist->previous();
    auto index = _playlist->currentIndex();
    emit currentIndexChanged(index);
}

void ControlModel::onPlayClicked()
{
    if (_player->state() == QMediaPlayer::State::PlayingState) {
        _player->pause();
    }
    else {
        _player->play();
        emit currentIndexChanged(_playlist->currentIndex());
    }
}

void ControlModel::onStopClicked() { _player->stop(); }

void ControlModel::onForwardClicked()
{
    _playlist->next();
    auto index = _playlist->currentIndex();
    emit currentIndexChanged(index);
}

void ControlModel::onMuteClicked(bool checked) { _player->setMuted(checked); }

void ControlModel::onShuffleClicked(bool isShuffle)
{
    _playlist->setPlaybackMode(isShuffle ? QMediaPlaylist::Random : QMediaPlaylist::Loop);
}

void ControlModel::onRepeatClicked(bool isRepeat)
{
    _playlist->setPlaybackMode(isRepeat ? QMediaPlaylist::CurrentItemInLoop : QMediaPlaylist::Loop);
}

void ControlModel::onSourceChanged(quint64 index)
{
    _playlist->setCurrentIndex(index);
    _player->play();

    emit currentIndexChanged(_playlist->currentIndex());
}

void ControlModel::onItemAdded(QString source) { _playlist->addMedia(QMediaContent(QUrl(source))); }
