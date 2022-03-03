/**
 * @file notification.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implementation for the pomwr notification window.
 * @copyright MIT License
 */

#include "notification.h"

#include <memory>

#include <QtCore/QPoint>
#include <QtCore/QRect>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QFont>
#include <QtGui/QPalette>

#include "miscutils.h"

namespace pwr {

// WaterNotif size of window, size of buttons, and button font def, palette
const QSize WaterNotif::window_size_ = QSize(400, 150);
const QSize WaterNotif::button_size_ = QSize(71, 41);
const QFont WaterNotif::button_font_ = QFont(QString("Consolas"), 24);

/**
 * Overloaded constructor for the WaterNotif that accepts a `QPalette &`.
 * 
 * WaterNotif is a subclass of QDialog that manages its own widget data, which
 * we initialize in the constructor. The WaterNotif is also capable of emitting
 * its own signals through slot functions.
 * 
 * @param palette `QPalette` reference set palette as. Defaults to whatever
 *     `QPalette` is returned by `pwr::BasePalette`.
 */
WaterNotif::WaterNotif(const QPalette &palette)
{
  FixWidgetSize(*this, WaterNotif::window_size_);
  this->setPalette(palette);
  // init + format the "yes" button. button text is "hai" in hiragana. this is
  // a flat style button with red 24 pt Consolas text.
  button_yes_ = std::make_unique<QPushButton>(
    QString("\343\201\257\343\201\204"), this
  );
  button_yes_->setGeometry(QRect(QPoint(30, 90), WaterNotif::button_size_));
  button_yes_->setStyleSheet(QString("QPushButton {color: #00ff00}"));
  button_yes_->setFont(WaterNotif::button_font_);
  button_yes_->setFlat(true);
  // init + format the "no" button. button text is "ie" in hiragana. this is a
  // flat style button with green 24 pt Consolas text.
  button_no_ = std::make_unique<QPushButton>(
    QString("\343\201\204\343\201\210"), this
  );
  button_no_->setGeometry(QRect(QPoint(300, 90), WaterNotif::button_size_));
  button_no_->setStyleSheet(QString("QPushButton {color: #ff0000}"));
  button_no_->setFont(WaterNotif::button_font_);
  button_no_->setFlat(true);
  // init + format the declarative label. font is auto size Consolas.
  label_decl_ = std::make_unique<QLabel>(
    "Pomu is telling you to drink your water!", this
  );
  label_decl_->setGeometry(QRect(10, 10, 291, 21));
  label_decl_->setFont(QFont("Consolas"));
  // init + format the prompt label. font is 12 pt Sans Serif bold.
  label_prompt_ = std::make_unique<QLabel>("Will you drink your water?", this);
  label_prompt_->setGeometry(QRect(10, 40, 241, 21));
  label_prompt_->setFont(QFont("Sans Serif", 12, QFont::Bold));
  // QMetaObject::connectSlotsByName(this);
}

/**
 * Default constructor for the `WaterNotif`.
 * 
 * Uses the `QPalette` returned by `pwr::BasePalette`.
 */
WaterNotif::WaterNotif() : WaterNotif(pwr::BasePalette()) {}

/**
 * Getters for QWidgets managed by the WaterNotif.
 * 
 * These can all be used to access and modify the state of the private QWidgets
 * while internally storage duration is managed by std::unique_ptr instances.
 */
QPushButton &WaterNotif::button_yes() const { return *button_yes_; }
QPushButton &WaterNotif::button_no() const { return *button_no_; }
QLabel &WaterNotif::label_decl() const { return *label_decl_; }
QLabel &WaterNotif::label_prompt() const { return *label_prompt_; }

} // namespace pwr
