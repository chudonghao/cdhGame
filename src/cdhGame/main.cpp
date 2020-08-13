#include <QApplication>
#include <iostream>

#include <cdhGame/runtime/App.h>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  if (!APP->setup(QApplication::applicationDirPath().toLocal8Bit().toStdString())) {
    std::cerr << "Can NOT init app. ERR: " << APP->stateStr() << std::endl;
    return -1;
  }

  APP->showMainWindow();

  QObject::connect(QApplication::instance(), &QApplication::aboutToQuit, [](){
    if(!APP->clearUp()){
      std::cerr << "Can NOT clear up app. ERR: " << APP->stateStr() << std::endl;
    }
  });

  return QApplication::exec();
}
