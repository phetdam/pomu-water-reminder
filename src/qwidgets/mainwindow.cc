/**
 * @file mainwindow.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implements the MainWindow methods.
 * @copyright MIT License
 */

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
    /*
    QApplication app = QApplication(argc, argv);
  app.setPalette(palette);
  QMainWindow main_window = QMainWindow();
  // make main_window non-resizable
  const QSize main_window_size = QSize(565, 565);
  main_window.resize(main_window_size);
  main_window.setMinimumSize(main_window_size);
  main_window.setMaximumSize(main_window_size);
  main_window.show();
    */
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
        MainWindow->resize(500, 686);
        MainWindow->setMinimumSize(QSize(500, 686));
        MainWindow->setMaximumSize(QSize(500, 686));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 85, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 127, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(106, 106, 158, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 42, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(57, 57, 85, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QBrush brush7(QColor(239, 239, 239, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        QBrush brush8(QColor(202, 202, 202, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        QBrush brush9(QColor(159, 159, 159, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        QBrush brush10(QColor(184, 184, 184, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush11(QColor(118, 118, 118, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush11);
        QBrush brush12(QColor(247, 247, 247, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush13(QColor(177, 177, 177, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
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
