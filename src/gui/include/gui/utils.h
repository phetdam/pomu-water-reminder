/**
 * @file utils.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header for QObject, primarily QWidget, utilities.
 * @copyright MIT License
 */

#include <QtCore/QSize>
#include <QtGui/QPalette>
#include <QtWidgets/QWidget>

#ifndef PWR_GUI_UTILS_H_
#define PWR_GUI_UTILS_H_

// for any QObject subclass, indicates that this QObject * is managed by the
// subclass instance and therefore does not need to be manually deleted.
#define QOBJECT_MANAGED_CHILD

namespace pwr {

QPalette BasePalette(void);
void FixWidgetSize(QWidget &, const QSize &);
void FixWidgetSize(QWidget &, int, int);

} // namespace pwr

#endif // PWR_GUI_UTILS_H_
