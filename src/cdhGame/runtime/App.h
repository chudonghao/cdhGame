//
// Created by chudonghao on 2020/8/9.
//

#ifndef CDHGAME_AB0DEC25AD6E46B9B91C616C83EF2EF1_
#define CDHGAME_AB0DEC25AD6E46B9B91C616C83EF2EF1_

#include "Log.h"
#include <QObject>
#include <exception>
#include <iostream>

class QTimer;

namespace cdhUi {
class MainWindow;
} // namespace cdhUi

namespace cdh3d {
class Viewer;
} // namespace cdh3d

namespace cdhMc {
class Match;
} // namespace cdhMc

namespace cdhRt {

class App : public QObject {
  Q_OBJECT;

public:
  static App *instance();
  bool setup(std::string dataPath);
  bool clearUp();

  cdhMc::Match *createMatch();
  bool startMatch();
  void destroyMatch();

  ///
  /// \throw std::runtime_error
  void show3dViewer();

  const std::string &stateStr() const { return _stateStr; }
  void showMainWindow() const;

public:
protected:
  App();
  std::string _stateStr;

  std::string _dataPath;

  cdhUi::MainWindow *_mainWindow{};
  cdh3d::Viewer *_3dViewer{};
  cdhMc::Match *_match{};
  QTimer *_viewerTimer{};
};

} // namespace cdhRt

#define APP cdhRt::App::instance()
#define APP_LOG_DEBUG cdhRt::Log(__FILE__, __LINE__, cdhRt::LOG_LEVEL_DEBUG)
#define APP_LOG_INFO cdhRt::Log(__FILE__, __LINE__, cdhRt::LOG_LEVEL_INFO)
#define APP_LOG_WARNING cdhRt::Log(__FILE__, __LINE__, cdhRt::LOG_LEVEL_WARNING)
#define APP_LOG_ERROR cdhRt::Log(__FILE__, __LINE__, cdhRt::LOG_LEVEL_ERROR)
#define APP_LOG_FATAL cdhRt::Log(__FILE__, __LINE__, cdhRt::LOG_LEVEL_FATAL)

#endif // CDHGAME_AB0DEC25AD6E46B9B91C616C83EF2EF1_
