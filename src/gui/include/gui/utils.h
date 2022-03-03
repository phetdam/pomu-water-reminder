/**
 * @file utils.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Declaration for QWidget utilities.
 * @copyright MIT License
 */

#include <QtCore/QSize>
#include <QtGui/QPalette>
#include <QtWidgets/QWidget>

#ifndef PWR_MISCUTILS_H_
#define PWR_MISCUTILS_H_

namespace pwr {

QPalette BasePalette(void);
void FixWidgetSize(QWidget &, const QSize &);
void FixWidgetSize(QWidget &, int, int);

} // namespace pwr

#endif // PWR_MISCUTILS_H_
