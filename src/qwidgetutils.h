/**
 * @file qwidgetutils.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Declaration for QWidget utilities.
 * @copyright MIT License
 */

#include <QtCore/QSize>
#include <QtGui/QPalette>
#include <QtWidgets/QWidget>

#ifndef PWR_BASEPALETTE_H_
#define PWR_BASEPALETTE_H_

namespace pwr {

QPalette BasePalette(void);
void FixWidgetSize(QWidget &, const QSize &);
void FixWidgetSize(QWidget &, int, int);

} // namespace pwr

#endif // PWR_BASEPALETTE_H_
