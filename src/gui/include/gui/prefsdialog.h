/**
 * @file prefsdialog.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the qtwr preferences dialog.
 * @copyright MIT License
 */

#ifndef QWR_GUI_PREFSDIALOG_H_
#define QWR_GUI_PREFSDIALOG_H_

#include <QtCore/QSize>
#include <QtGui/QFont>
#include <QtGui/QPalette>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace qwr {

class PrefsDialog: public QDialog
{
public:
  PrefsDialog();
  PrefsDialog(QWidget *);
  PrefsDialog(QWidget *, const QPalette &);
  QCheckBox *sounds_checkbox() const;

private:
  static const QSize dialog_size_;
  static const QFont dialog_font_;
  QOBJECT_MANAGED_CHILD QCheckBox *sounds_checkbox_;
};

} // namespace qwr

#endif // QWR_GUI_PREFSDIALOG_H_
