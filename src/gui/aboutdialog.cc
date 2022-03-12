/**
 * @file aboutdialog.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implements the qtwr about dialog.
 * @copyright MIT License
 */

#include "gui/aboutdialog.h"

#include <QtCore/QRect>
#include <QtCore/QSize>
#include <QtCore/Qt>
#include <QtGui/QPalette>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

// size, label position, label text of about dialog
const QSize AboutDialog::dialog_size_ = QSize(290, 80);
const QRect AboutDialog::text_label_rect_ = QRect(10, 10, 280, 60);
const char *AboutDialog::text_label_text_ =
  "A Qt6 app to remind you to drink your water.\n"
  "\n"
  "A first C++ project by [Derek Huang](https://github.com/phetdam/).";

/**
 * Overloaded constructor for the `AboutDialog`.
 * 
 * @param parent `QWidget *` for parent `QObject`.
 * @param palette `const` `QPalette &` giving desired dialog palette.
 */
AboutDialog::AboutDialog(QWidget *parent, const QPalette &palette)
  : QDialog(parent)
{
  FixWidgetSize(*this, AboutDialog::dialog_size_);
  setPalette(palette);
  setWindowTitle("Preferences");
  setModal(true);
  text_label_ = new QLabel(AboutDialog::text_label_text_, this);
  text_label_->setGeometry(AboutDialog::text_label_rect_);
  text_label_->setTextFormat(Qt::MarkdownText);
}

/**
 * Overloaded constructor for the `AboutDialog`.
 * 
 * Uses the preferred default palette returned by `qwr::BasePalette`.
 * 
 * @param parent `QWidget *` for parent `QObject`.
 */
AboutDialog::AboutDialog(QWidget *parent) : AboutDialog(parent, BasePalette())
{}

AboutDialog::AboutDialog() : AboutDialog(nullptr) {}

} // namespace qwr
