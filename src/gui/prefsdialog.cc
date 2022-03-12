/**
 * @file prefsdialog.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implements the qtwr preferences dialog.
 * @copyright MIT License
 * 
 * Adapted from the auto-generated C++ code from Qt Designer.
 */

#include "gui/prefsdialog.h"

#include <QtCore/QSize>
#include <QtGui/QFont>
#include <QtGui/QPalette>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

// size and font of the preferences dialog
const QSize PrefsDialog::dialog_size_ = QSize(200, 80);
const QFont PrefsDialog::dialog_font_ = QFont("Consolas");

/**
 * Overloaded `PrefsDialog` constructor.
 * 
 * This is the window that pops up when `Settings -> Preferences` is accessed
 * through the main menu of the `MainWindow` instance.
 * 
 * @param parent `QWidget *` to parent widget
 * @param palette `QPalette &` to desired palette
 */
PrefsDialog::PrefsDialog(QWidget *parent, const QPalette &palette)
  : QDialog(parent)
{
  FixWidgetSize(*this, PrefsDialog::dialog_size_);
  setPalette(palette);
  setWindowTitle("Preferences");
  setModal(true);
  setFont(PrefsDialog::dialog_font_);
  sounds_checkbox_ = new QCheckBox("Enable sounds", this);
  sounds_checkbox_->setGeometry(10, 10, 121, 20);
}

/**
 * Overloaded `PrefsDialog` constructor with no `palette` argument.
 * 
 * Uses `pwr::BasePalette` for the default `QPalette`.
 * 
 * @param parent `QWidget *` to parent widget.
 */
PrefsDialog::PrefsDialog(QWidget *parent) : PrefsDialog(parent, BasePalette())
{}

/**
 * Default `PrefsDialog` constructor.
 * 
 * No parent and uses the `QPalette` from `qwr::BasePalette`.
 */
PrefsDialog::PrefsDialog() : PrefsDialog(nullptr) {}

} // namespace qwr
