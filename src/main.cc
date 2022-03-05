/**
 * @file main.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Main entry point for app.
 * @copyright MIT License
 */

#include <iostream>
#include <memory>

#include <QtCore/QSize>
#include <QtCore/Qt>
#include <QtGui/QColor>
#include <QtGui/QIcon>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenu>

#include "gui/alertdialog.h"
#include "gui/mainwindow.h"
#include "gui/prefsdialog.h"
#include "gui/utils.h"

int main(int argc, char **argv)
{
  QPalette palette = qwr::BasePalette();
  QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  std::unique_ptr<qwr::MainWindow> main_window =
    std::make_unique<qwr::MainWindow>();
  // remove later -- just to demonstrate some dialogs
  QOBJECT_MANAGED_CHILD qwr::AlertDialog *alert_dialog = new qwr::AlertDialog(
    main_window.get()
  );
  QOBJECT_MANAGED_CHILD qwr::PrefsDialog *prefs_dialog = new qwr::PrefsDialog(
    main_window.get()
  );
  // show window/dialogs
  main_window->show();
  alert_dialog->show();
  prefs_dialog->show();
  return app.exec();
}