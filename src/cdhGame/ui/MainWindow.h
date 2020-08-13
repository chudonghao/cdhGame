//
// Created by chudonghao on 2020/8/9.
//

#ifndef CDHGAME_16C9E0FC6F6F424F9BB6B2BCFA3349D0_
#define CDHGAME_16C9E0FC6F6F424F9BB6B2BCFA3349D0_

#include <QWidget>

namespace Ui {
class MainWindow;
} // namespace Ui
namespace cdhUi {

class MainWindow : public QWidget {
  Q_OBJECT;

public:
  MainWindow();
  virtual ~MainWindow();

private:
  using Ui = ::Ui::MainWindow;
  Ui *ui{};
};

} // namespace cdhUi

#endif // CDHGAME_16C9E0FC6F6F424F9BB6B2BCFA3349D0_
