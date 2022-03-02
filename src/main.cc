/**
 * @file main.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Main entry point for app.
 * @copyright MIT License
 */

#include <QtCore/QSize>
#include <QtGui/QColor>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char **argv)
{
  QPalette palette = QPalette(QColor("#55557f"));
  QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  QMainWindow main_window = QMainWindow();
  // make main_window non-resizable
  const QSize main_window_size = QSize(500, 686);
  main_window.resize(main_window_size);
  main_window.setMinimumSize(main_window_size);
  main_window.setMaximumSize(main_window_size);
  main_window.show();
  return app.exec();
}