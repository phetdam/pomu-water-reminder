/**
 * @file mainwindow.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implements the main pomwr application window.
 * @copyright MIT License
 */

#include "gui/mainwindow.h"

#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QCloseEvent>
#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace pwr {

// sizes of the main window, central QLabel displaying Pomu
const QSize MainWindow::window_size_ = QSize(565, 585);
const QSize MainWindow::image_size_ = QSize(565, 565);

/**
 * Overloaded `MainWindow` constructor accepting a `QPalette &`.
 * 
 * @param palette Reference to desired `QPalette`
 */
MainWindow::MainWindow(const QPalette &palette)
{
  // set size and palette for MainWindow
  FixWidgetSize(*this, MainWindow::window_size_);
  setPalette(palette);
  // QMainWindow main widget displaying Pomu. the QMainWindow base class needs
  // and owns the central widget, freeing when necessary.
  image_label_ = new QLabel(this);
  setCentralWidget(image_label_);
  FixWidgetSize(*image_label_, MainWindow::image_size_);
  image_label_->setPixmap(QPixmap(QString(":/images/pomu_rainpuff_smile.png")));
  // menu bar setup. MainWindow will own and deallocate this object
  menuBar();
  // add toolbar and toolbar actions
  // status bar setup. MainWindow will own and deallocate this object
  statusBar()->setSizeGripEnabled(false);
}

/**
 * `MainWindow` default constructor.
 * 
 * Uses the default `QPalette` provided by `pwr::BasePalette`.
 */
MainWindow::MainWindow() : MainWindow(BasePalette()) {}

/**
 * Handles the `QCloseEvent` received when one attempts to close the app.
 * 
 * @param event `QCloseEvent` pointer to the triggering event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
  // todo: if not saved, pop up a window
  event->accept();
}

/**
 * Getters for QWidgets managed by the MainWindow.
 * 
 * These can all be used to access and modify the state of the private QWidgets
 * while internally storage duration is managed by std::unique_ptr instances.
 */
QMenuBar *MainWindow::menu_bar() const { return menuBar(); }
QStatusBar *MainWindow::status_bar() const { return statusBar(); }

/*
class Ui_MainWindow
{
  //   QApplication app = QApplication(argc, argv);
  // app.setPalette(palette);
  // QMainWindow main_window = QMainWindow();
  // // make main_window non-resizable
  // const QSize main_window_size = QSize(565, 565);
  // main_window.resize(main_window_size);
  // main_window.setMinimumSize(main_window_size);
  // main_window.setMaximumSize(main_window_size);
  // main_window.show();
public:
    QAction *actionSave_Profile_As;
    QAction *actionPreferences;
    QAction *actionLoad_Profile;
    QAction *actionAbout;
    QAction *actionAbout_2;
    QAction *actionConfiguration;
    QWidget *centralwidget;
    QTimeEdit *timeEdit;
    QLabel *label;
    QTimeEdit *timeEdit_2;
    QLabel *label_2;
    QTimeEdit *timeEdit_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *pomu_label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuPreferences;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        actionSave_Profile_As = new QAction(MainWindow);
        actionSave_Profile_As->setObjectName(QString::fromUtf8("actionSave_Profile_As"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionLoad_Profile = new QAction(MainWindow);
        actionLoad_Profile->setObjectName(QString::fromUtf8("actionLoad_Profile"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_2 = new QAction(MainWindow);
        actionAbout_2->setObjectName(QString::fromUtf8("actionAbout_2"));
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(10, 30, 118, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 51, 16));
        timeEdit_2 = new QTimeEdit(centralwidget);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(150, 30, 118, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 10, 51, 16));
        timeEdit_3 = new QTimeEdit(centralwidget);
        timeEdit_3->setObjectName(QString::fromUtf8("timeEdit_3"));
        timeEdit_3->setGeometry(QRect(10, 80, 118, 22));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 51, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 120, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 120, 75, 24));
        pomu_label = new QLabel(centralwidget);
        pomu_label->setObjectName(QString::fromUtf8("pomu_label"));
        pomu_label->setGeometry(QRect(0, 0, 500, 644));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pomu_label->sizePolicy().hasHeightForWidth());
        pomu_label->setSizePolicy(sizePolicy);
        pomu_label->setPixmap(QPixmap(QString::fromUtf8(":/images/pomu_rainpuff_portrait.png")));
        pomu_label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        pomu_label->raise();
        timeEdit->raise();
        label->raise();
        timeEdit_2->raise();
        label_2->raise();
        timeEdit_3->raise();
        label_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 19));
        menubar->setStyleSheet(QString::fromUtf8("font-family: \"Consola\", monospace"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuPreferences = new QMenu(menubar);
        menuPreferences->setObjectName(QString::fromUtf8("menuPreferences"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuPreferences->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave_Profile_As);
        menuFile->addAction(actionLoad_Profile);
        menuPreferences->addAction(actionConfiguration);
        menuPreferences->addAction(actionPreferences);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pomu Water Reminder", nullptr));
        actionSave_Profile_As->setText(QCoreApplication::translate("MainWindow", "Save Profile As...", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
        actionLoad_Profile->setText(QCoreApplication::translate("MainWindow", "Load Profile", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "Keyboard Shortcuts", nullptr));
        actionAbout_2->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionConfiguration->setText(QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Start time", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "End time", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Repeat", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Show stats", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Reset stats", nullptr));
        pomu_label->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuPreferences->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};
*/

} // namespace pwr
