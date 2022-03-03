/**
 * @file utils.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Defines QWidget utility functions.
 * @copyright MIT License
 */

#include "gui/utils.h"

#include <QtGui/QBrush>
#include <QtGui/QPalette>
#include <QtWidgets/QWidget>

namespace pwr {

/**
 * Return the base palette used by the pomwr app.
 * 
 * Base color is a darkish purple, specifically #55557f.
 *
 * @returns `QPalette`
 */
QPalette BasePalette(void) {
  QPalette palette = QPalette(QColor("#55557f"));
  palette.setBrush(QPalette::Active, QPalette::WindowText, QBrush(Qt::white));
  palette.setBrush(QPalette::Active, QPalette::ButtonText, QBrush(Qt::white));
  return palette;
}

/**
 * Fix the widget to the specified QSize.
 * 
 * @param widget A reference to the desired `QWidget` in question.
 * @param size A reference to the desired `QSize` to fix `widget` at.
 */
void FixWidgetSize(QWidget &widget, const QSize &size)
{
  widget.resize(size);
  widget.setMinimumSize(size);
  widget.setMaximumSize(size);
}

/**
 * Fix the widget to the specified height and width.
 * 
 * @param width Width of the `QWidget` in px.
 * @param height Height of the `QWidget` in px.
 */
void FixWidgetSize(QWidget &widget, int width, int height)
{
  widget.resize(width, height);
  widget.setMinimumSize(width, height);
  widget.setMaximumSize(width, height);
}

} // namespace pwr
