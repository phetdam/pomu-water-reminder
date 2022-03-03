/**
 * @file mainwindow.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the main pomwr application window.
 * @copyright MIT License
 */

#include <QtCore/Qt>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

#ifndef PWR_MAINWINDOW_H_
#define PWR_MAINWINDOW_H_

class MainWindow: public QMainWindow
{
public:
  MainWindow(QWidget * = nullptr);
  ~MainWindow();
private:
  
};

#endif // PWR_MAINWINDOW_H_