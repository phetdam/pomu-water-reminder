/**
 * @file mainwindow.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the main qtwr application window.
 * @copyright MIT License
 */

#include <memory>

#include <QtCore/QSize>
#include <QtCore/Qt>
#include <QtGui/QAction>
#include <QtGui/QCloseEvent>
#include <QtGui/QHideEvent>
#include <QtGui/QPalette>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>

#include "gui/utils.h"

#ifndef QWR_GUI_MAINWINDOW_H_
#define QWR_GUI_MAINWINDOW_H_

namespace qwr {

class MainWindow: public QMainWindow
{
public:
  MainWindow();
  MainWindow(const QPalette &);
  QLabel *image_label() const;
  QMenuBar *menu_bar() const;
  QMenu *file_menu() const;
  QMenu *settings_menu() const;
  QMenu *help_menu() const;
  QAction *save_profile_action() const;
  QAction *load_profile_action() const;
  QAction *config_action() const;
  QAction *prefs_action() const;
  QAction *key_shortcuts_action() const;
  QAction *about_action() const;
  QStatusBar *status_bar() const;

protected:
  void closeEvent(QCloseEvent *);

private:
  static const QSize window_size_;
  static const QSize image_size_;
  QOBJECT_MANAGED_CHILD QLabel *image_label_;
  QOBJECT_MANAGED_CHILD QMenu *view_menu_;
  QOBJECT_MANAGED_CHILD QMenu *settings_menu_;
  QOBJECT_MANAGED_CHILD QMenu *help_menu_;
  QOBJECT_MANAGED_CHILD QAction *stats_action_;
  QOBJECT_MANAGED_CHILD QAction *config_action_;
  QOBJECT_MANAGED_CHILD QAction *prefs_action_;
  QOBJECT_MANAGED_CHILD QAction *key_shortcuts_action_;
  QOBJECT_MANAGED_CHILD QAction *about_action_;
};

} // namespace qwr

#endif // QWR_GUI_MAINWINDOW_H_