/**
 * @file main.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Main entry point for app.
 * @copyright MIT License
 */

#include <memory>

#include <QtCore/QSize>
#include <QtGui/QColor>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include "gui/utils.h"
#include "gui/alert.h"

int main(int argc, char **argv)
{
  QPalette palette = pwr::BasePalette();
  QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  QMainWindow main_window = QMainWindow();
  // make main_window non-resizable
  pwr::FixWidgetSize(main_window, QSize(565, 565));
  // remove later -- just to demonstrate the notification window
  std::unique_ptr<pwr::WaterAlert> notif_window =
    std::make_unique<pwr::WaterAlert>();
  // show both windows
  main_window.show();
  notif_window->show();
  return app.exec();
}