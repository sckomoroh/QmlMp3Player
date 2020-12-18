#ifndef _RootContext_H_
#define _RootContext_H_

#include <QObject>

#include "ControlModel.h"
#include "PlaylistModel.h"

class RootContext final : public QObject {
    Q_OBJECT
private:
    PlaylistModel* _playlistModel;
    ControlModel* _controlModel;

public:
    RootContext(QObject* parent = nullptr);

public:
    Q_PROPERTY(PlaylistModel* playlistModel READ playlistModel CONSTANT);
    Q_PROPERTY(ControlModel* controlModel READ controlModel CONSTANT);

public:
    PlaylistModel* playlistModel() const;
    ControlModel* controlModel() const;
};

#endif  // _RootContext_H_
