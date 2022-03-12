/**
 * @file aboutdialog.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the qtwr about dialog.
 * @copyright MIT License
 */

#ifndef QWR_GUI_ABOUTDIALOG_H_
#define QWR_GUI_ABOUTDIALOG_H_

#include <QtCore/QRect>
#include <QtCore/QSize>
#include <QtGui/QPalette>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

class AboutDialog: public QDialog
{
public:
  AboutDialog();
  AboutDialog(QWidget *);
  AboutDialog(QWidget *, const QPalette &);
  QLabel *text_label() const;

private:
  static const char *text_label_text_;
  static const QSize dialog_size_;
  static const QRect text_label_rect_;
  QOBJECT_MANAGED_CHILD QLabel *text_label_;
};

} // namespace qwr

#endif // QWR_GUI_ABOUTDIALOG_H_
