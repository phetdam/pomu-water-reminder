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

#include "qwidgetutils.h"
#include "waternotif.h"

int main(int argc, char **argv)
{
  QPalette palette = pwr::BasePalette();
  QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  QMainWindow main_window = QMainWindow();
  // make main_window non-resizable
  QSize main_window_size = QSize(565, 565);
  main_window.resize(main_window_size);
  main_window.setMinimumSize(main_window_size);
  main_window.setMaximumSize(main_window_size);
  main_window.show();
  // remove later -- just to demonstrate the notification window
  std::unique_ptr<pwr::WaterNotif> notif_window =
    std::make_unique<pwr::WaterNotif>();
  notif_window->show();
  return app.exec();
}