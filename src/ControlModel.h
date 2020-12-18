#ifndef _ControlModel_H_
#define _ControlModel_H_

#include <QMediaPlayer>
#include <QObject>

class ControlModel : public QObject {
    Q_OBJECT
private:
    QMediaPlayer* _player;
    QMediaPlaylist* _playlist;

public:
    ControlModel(QObject* parent = nullptr);

public slots:
    void onPositionChanged(double value);
    void onVolumeChanged(double value);

    void onBackwardClicked();
    void onPlayClicked();
    void onStopClicked();
    void onForwardClicked();

    void onMuteClicked(bool checked);
    void onShuffleClicked(bool checked);
    void onRepeatClicked(bool checked);

    void onSourceChanged(quint64 index);
    void onItemAdded(QString source);

signals:
    void currentIndexChanged(int index);
};

#endif  // _ControlModel_H_
