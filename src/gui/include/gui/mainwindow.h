/**
 * @file mainwindow.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the main pomwr application window.
 * @copyright MIT License
 */

#include <memory>

#include <QtCore/Qt>
#include <QtGui/QAction>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#ifndef PWR_MAINWINDOW_H_
#define PWR_MAINWINDOW_H_

class MainWindow: public QMainWindow
{
public:
  MainWindow(QWidget * = nullptr);
  QLabel &image_label() const;
  QMenuBar &menu_bar() const;
  QMenu &file_menu() const;
  QMenu &settings_menu() const;
  QMenu &help_menu() const;
  QAction &save_profile_action() const;
  QAction &load_profile_action() const;
  QAction &config_action() const;
  QAction &prefs_action() const;
  QAction &key_shortcuts_action() const;
  QAction &about_action() const;
  QStatusBar &status_bar() const;

private:
  std::unique_ptr<QLabel> image_label_;
  std::unique_ptr<QMenu> file_menu_;
  std::unique_ptr<QMenu> settings_menu_;
  std::unique_ptr<QMenu> help_menu_;
  std::unique_ptr<QAction> save_profile_action_;
  std::unique_ptr<QAction> load_profile_action_;
  std::unique_ptr<QAction> config_action_;
  std::unique_ptr<QAction> prefs_action_;
  std::unique_ptr<QAction> key_shortcuts_action_;
  std::unique_ptr<QAction> about_action_;
};

#endif // PWR_MAINWINDOW_H_