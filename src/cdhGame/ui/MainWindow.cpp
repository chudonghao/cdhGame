//
// Created by chudonghao on 2020/8/9.
//

#include "MainWindow.h"

#include <cdhGame/runtime/App.h>

#include "ui_MainWindow.h"

using namespace std;
using namespace cdhUi;

MainWindow::MainWindow() : ui(new Ui) {
  ui->setupUi(this);
  connect(ui->startGameButton, &QPushButton::clicked, []() { APP->show3dViewer(); });
}
MainWindow::~MainWindow() { delete ui; }
