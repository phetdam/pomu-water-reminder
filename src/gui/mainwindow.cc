/**
 * @file mainwindow.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implements the main qtwr application window.
 * @copyright MIT License
 */

#include "gui/mainwindow.h"

#include <QtCore/Qt>
#include <QtGui/QAction>
#include <QtGui/QCloseEvent>
#include <QtGui/QHideEvent>
#include <QtGui/QIcon>
#include <QtGui/QPalette>
#include <QtGui/QPixmap>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>

#include "gui/utils.h"

namespace qwr {

// sizes of the main window, central QLabel displaying water image
const QSize MainWindow::window_size_ = QSize(550, 550);
const QSize MainWindow::image_size_ = QSize(550, 550);

/**
 * Overloaded `MainWindow` constructor accepting a `QPalette &`.
 * 
 * The main window of the application, with all menus and the parent of the
 * different window components we show. Cannot be minimized or maximized.
 * 
 * @param palette Reference to desired `QPalette`
 */
MainWindow::MainWindow(const QPalette &palette)
{
  // set size, palette, icon, window flags for MainWindow
  FixWidgetSize(*this, MainWindow::window_size_);
  setPalette(palette);
  setWindowIcon(QIcon(":/images/water_icon.png"));
  setWindowFlag(Qt::WindowMinimizeButtonHint, false);
  // QMainWindow main widget displaying water. the QMainWindow base class needs
  // and owns the central widget, freeing when necessary.
  image_label_ = new QLabel(this);
  setCentralWidget(image_label_);
  FixWidgetSize(*image_label_, MainWindow::image_size_);
  image_label_->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
  image_label_->setPixmap(QPixmap(":/images/water.png"));
  // menu bar and menu setup. MainWindow owns the menu bar, which owns menus
  menu_bar();
  file_menu_ = menu_bar()->addMenu("&File");
  settings_menu_ = menu_bar()->addMenu("&Settings");
  help_menu_ = menu_bar()->addMenu("&Help");
  // create individual actions for menus, owned by the MainWindow
  save_profile_action_ = new QAction("&Save Profile As...", this);
  load_profile_action_ = new QAction("&Load Profile...", this);
  config_action_ = new QAction("&Configuration", this);
  prefs_action_ = new QAction("&Preferences", this);
  key_shortcuts_action_ = new QAction("&Keyboard Shortcuts", this);
  about_action_ = new QAction("&About", this);
  // add menu actions to menu bar and individual actions to menus
  menu_bar()->addAction(file_menu_->menuAction());
  menu_bar()->addAction(settings_menu_->menuAction());
  menu_bar()->addAction(help_menu_->menuAction());
  file_menu_->addAction(save_profile_action_);
  file_menu_->addAction(load_profile_action_);
  settings_menu_->addAction(config_action_);
  settings_menu_->addAction(prefs_action_);
  help_menu_->addAction(key_shortcuts_action_);
  help_menu_->addAction(about_action_);
  // status bar setup. MainWindow will own and deallocate this object
  status_bar()->setSizeGripEnabled(false);
}

/**
 * `MainWindow` default constructor.
 * 
 * Uses the default `QPalette` provided by `qwr::BasePalette`.
 */
MainWindow::MainWindow() : MainWindow(BasePalette()) {}

/**
 * Handles the `QCloseEvent` received when one attempts to close the app.
 * 
 * @param event `QCloseEvent` pointer to the triggering event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
  // todo: if not saved, pop up a window
  event->accept();
}

/**
 * Getters for QWidgets managed by the MainWindow.
 * 
 * These can all be used to access and modify the state of the private QWidgets
 * while internally storage duration is managed by std::unique_ptr instances.
 */
QMenuBar *MainWindow::menu_bar() const { return menuBar(); }
QStatusBar *MainWindow::status_bar() const { return statusBar(); }

} // namespace qwr
