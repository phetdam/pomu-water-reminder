/**
 * @file keydialog.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implements the qtwr keyboard shortcuts dialog.
 * @copyright MIT License
 */

#include "gui/keydialog.h"

#include <QtCore/QRect>
#include <QtCore/QSize>
#include <QtCore/Qt>
#include <QtGui/QPalette>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

// size, label position, label text of shortcuts dialog
const QSize KeyDialog::dialog_size_ = QSize(340, 85);
const QRect KeyDialog::text_label_rect_ = QRect(10, 10, 320, 60);
const char *KeyDialog::text_label_text_ =
  "Press `Alt` to enable keyboard shortcuts. Subsequent key presses will then "
  "trigger menu commands.\n"
  "\n"
  "For example, `Alt` + `H` + `K` opens this dialog.";

/**
 * Overloaded `KeyDialog` constructor.
 * 
 * A window that pops up when `Help -> Keyboard Shortcuts` is accessed through
 * the main menu of the `MainWindow` instance.
 * 
 * @param parent `QWidget *` to parent widget
 * @param palette `QPalette &` to desired palette
 */
KeyDialog::KeyDialog(QWidget *parent, const QPalette &palette) : QDialog(parent)
{
  FixWidgetSize(*this, KeyDialog::dialog_size_);
  setPalette(palette);
  setWindowTitle("Keyboard Shortcuts");
  setModal(true);
  text_label_ = new QLabel(KeyDialog::text_label_text_, this);
  text_label_->setGeometry(KeyDialog::text_label_rect_);
  text_label_->setTextFormat(Qt::MarkdownText);
  text_label_->setWordWrap(true);
}

/**
 * Overloaded `KeyDialog` constructor.
 * 
 * Uses default `QPalette` returned by `qwr::BasePalette`.
 * 
 * @param parent `QWidget *` to parent widget.
 */
KeyDialog::KeyDialog(QWidget *parent) : KeyDialog(parent, BasePalette()) {}

KeyDialog::KeyDialog() : KeyDialog(nullptr) {}

QLabel *KeyDialog::text_label() const { return text_label_; }

} // namespace qwr
