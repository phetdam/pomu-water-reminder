/**
 * @file main.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Main entry point for app.
 * @copyright MIT License
 */

#include <memory>

#include <QtCore/QSize>
#include <QtCore/Qt>
#include <QtGui/QColor>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>

#include "gui/alert.h"
#include "gui/mainwindow.h"
#include "gui/utils.h"

int main(int argc, char **argv)
{
  QPalette palette = pwr::BasePalette();
  QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  std::unique_ptr<pwr::MainWindow> main_window =
    std::make_unique<pwr::MainWindow>();
  // remove later -- just to demonstrate the notification window
  QOBJECT_MANAGED_CHILD pwr::WaterAlert *notif_window =
    new pwr::WaterAlert(main_window.get());
  // show both windows
  main_window->show();
  notif_window->show();
  return app.exec();
}