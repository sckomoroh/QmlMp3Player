#include "RootContext.h"

RootContext::RootContext(QObject* parent)
    : QObject{parent}
    , _playlistModel{new PlaylistModel{this}}
    , _controlModel{new ControlModel{this}}
{
    connect(_playlistModel,
        &PlaylistModel::sourceChanged,
        _controlModel,
        &ControlModel::onSourceChanged);

    connect(_playlistModel, &PlaylistModel::itemAdded, _controlModel, &ControlModel::onItemAdded);
}

PlaylistModel* RootContext::playlistModel() const { return _playlistModel; }

ControlModel* RootContext::controlModel() const { return _controlModel; }
