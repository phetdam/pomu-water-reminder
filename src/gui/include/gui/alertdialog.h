/**
 * @file alertdialog.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the qtwr water reminder alert dialog.
 * @copyright MIT License
 */

#ifndef QWR_GUI_ALERTDIALOG_H_
#define QWR_GUI_ALERTDIALOG_H_

#include <QtCore/QSize>
#include <QtGui/QFont>
#include <QtGui/QPalette>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

class AlertDialog: public QDialog
{
public:
  AlertDialog();
  AlertDialog(QWidget *);
  AlertDialog(QWidget *, const QPalette &);
  QPushButton *button_yes() const;
  QPushButton *button_no() const;
  QLabel *label_decl() const;
  QLabel *label_prompt() const;

private:
  static const QSize dialog_size_;
  static const QSize button_size_;
  static const QFont button_font_;
  QOBJECT_MANAGED_CHILD QPushButton *button_yes_;
  QOBJECT_MANAGED_CHILD QPushButton *button_no_;
  QOBJECT_MANAGED_CHILD QLabel *label_decl_;
  QOBJECT_MANAGED_CHILD QLabel *label_prompt_;
};

} // namespace qwr

#endif // QWR_GUI_ALERTDIALOG_H_
