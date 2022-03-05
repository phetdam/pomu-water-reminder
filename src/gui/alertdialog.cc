/**
 * @file alertdialog.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implementation for the qtwr water alert dialog.
 * @copyright MIT License
 * 
 * Adapted from the auto-generated C++ code from Qt Designer.
 */

#include "gui/alertdialog.h"

#include <QtCore/QPoint>
#include <QtCore/QRect>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QFont>
#include <QtGui/QPalette>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

// AlertDialog size of dialog, size of buttons, and button font def, palette
const QSize AlertDialog::dialog_size_ = QSize(400, 150);
const QSize AlertDialog::button_size_ = QSize(71, 41);
const QFont AlertDialog::button_font_ = QFont(QString("Consolas"), 24);

/**
 * Overloaded constructor for the `AlertDialog` that accepts a `QPalette &`.
 * 
 * `AlertDialog` is an application-modal subclass of `QDialog` that manages its
 * own widget data, which we initialize in the constructor.
 * 
 * @param parent `QWidget` pointer to a parent widget.
 * @param palette `QPalette` reference to set the palette as. Defaults to
 *     whatever `QPalette` is returned by `qwr::BasePalette`.
 */
AlertDialog::AlertDialog(QWidget *parent, const QPalette &palette)
  : QDialog(parent)
{
  FixWidgetSize(*this, AlertDialog::dialog_size_);
  setPalette(palette);
  setModal(true);
  // init + format the "yes" button. button text is "hai" in hiragana. this is
  // a flat style button with red 24 pt Consolas text. note that since we set
  button_yes_ = new QPushButton(QString("\343\201\257\343\201\204"), this);
  button_yes_->setGeometry(QRect(QPoint(30, 90), AlertDialog::button_size_));
  button_yes_->setStyleSheet(QString("QPushButton {color: #00ff00}"));
  button_yes_->setFont(AlertDialog::button_font_);
  button_yes_->setFlat(true);
  // init + format the "no" button. button text is "ie" in hiragana. this is a
  // flat style button with green 24 pt Consolas text.
  button_no_ = new QPushButton(QString("\343\201\204\343\201\210"), this);
  button_no_->setGeometry(QRect(QPoint(300, 90), AlertDialog::button_size_));
  button_no_->setStyleSheet(QString("QPushButton {color: #ff0000}"));
  button_no_->setFont(AlertDialog::button_font_);
  button_no_->setFlat(true);
  // init + format the declarative label. font is auto size Consolas.
  label_decl_ = new QLabel("It's time to drink your water!", this);
  label_decl_->setGeometry(10, 10, 291, 21);
  label_decl_->setFont(QFont("Consolas"));
  // init + format the prompt label. font is 12 pt Sans Serif bold.
  label_prompt_ = new QLabel("Will you drink your water?", this);
  label_prompt_->setGeometry(10, 40, 241, 21);
  label_prompt_->setFont(QFont("Sans Serif", 12, QFont::Bold));
}

/**
 * Overloaded constructor for the `AlertDialog`.
 * 
 * Uses the `QPalette` returned by `qwr::BasePalette`.
 * 
 * @param parent `QWidget` pointer to a parent widget.
 */
AlertDialog::AlertDialog(QWidget *parent) : AlertDialog(parent, BasePalette())
{}

/**
 * Default constructor for the `AlertDialog`.
 * 
 * No parent `QWidget` and uses the `QPalette` from `qwr::BasePalette`.
 */
AlertDialog::AlertDialog() : AlertDialog(nullptr) {}

/**
 * Getters for QWidgets managed by the AlertDialog.
 * 
 * These can all be used to access and modify the state of the private QWidgets
 * while internally storage duration is managed by std::unique_ptr instances.
 */
QPushButton *AlertDialog::button_yes() const { return button_yes_; }
QPushButton *AlertDialog::button_no() const { return button_no_; }
QLabel *AlertDialog::label_decl() const { return label_decl_; }
QLabel *AlertDialog::label_prompt() const { return label_prompt_; }

} // namespace qwr
