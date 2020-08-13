//
// Created by chudonghao on 2020/8/9.
//

#include "App.h"

#include <QTime>
#include <QTimer>
#include <cdhGame/3d/Viewer.h>
#include <cdhGame/match/Match.h>
#include <cdhGame/ui/MainWindow.h>
#include <filesystem>
#include <osgDB/Registry>
#include <utility>

using namespace std;
using namespace cdhRt;

namespace {
App *app;
} // namespace

App::App() {
  _viewerTimer = new QTimer;
  _viewerTimer->setInterval(0);
}

App *cdhRt::App::instance() {
  if (!app) {
    app = new App;
  }
  return app;
}

bool App::setup(std::string dataPath) {
  if (_mainWindow) {
    _mainWindow->deleteLater();
  }

  _dataPath = std::move(dataPath);
  if (_dataPath.empty()) {
    _dataPath = std::filesystem::current_path();
  }

  _mainWindow = new cdhUi::MainWindow;
  _stateStr = "already setup.";
  return true;
}

void App::showMainWindow() const {
  if (_mainWindow) {
    _mainWindow->show();
  }
}
bool App::clearUp() {
  if (_mainWindow) {
    _mainWindow->deleteLater();
  }
  deleteLater();
  app = nullptr;
  _stateStr = "already clear up.";
  return true;
}
void App::show3dViewer() {
  if (!_3dViewer) {
    _3dViewer = new cdh3d::Viewer;
    _3dViewer->setUpViewInWindow(100, 100, 800, 800);
    connect(_viewerTimer, &QTimer::timeout, [=]() {
      if (_3dViewer) {
        _3dViewer->frame();
      }
    });
    _viewerTimer->start();
    auto dbOpts = new osgDB::Options;
    dbOpts->setDatabasePath(_dataPath);
    _3dViewer->setDatabaseOptions(dbOpts);
  }
  _3dViewer->loadPlayground();
}
cdhMc::Match *App::createMatch() {
  if (_match) {
    return _match;
  }
  _match = new cdhMc::Match(QTime::currentTime().second());
  return _match;
}
void App::destroyMatch() {
  delete _match;
  _match = nullptr;
}
bool App::startMatch() {
  _match->start();
  return true;
}
