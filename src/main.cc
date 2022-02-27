/**
 * @file main.cc
 * @brief Main entry point for app.
 */

#include <QtGui/QColor>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>

int main(int argc, char **argv)
{
  const QPalette palette = QPalette(QColor("55557f"));
  QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  return app.exec();
}