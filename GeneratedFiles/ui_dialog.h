/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *display_screen;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *film_Button;
    QPushButton *kamera_Button;
    QPushButton *zdjecie_Button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *wykrywanie_Button;
    QPushButton *stop_Button;
    QTableWidget *tableWidget;
    QLabel *frame_counter;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QPushButton *ok;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(1072, 845);
        Dialog->setMinimumSize(QSize(981, 621));
        QIcon icon;
        icon.addFile(QStringLiteral("obrazy/006-roundabout.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setAutoFillBackground(false);
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(false);
        display_screen = new QLabel(Dialog);
        display_screen->setObjectName(QStringLiteral("display_screen"));
        display_screen->setEnabled(true);
        display_screen->setGeometry(QRect(10, 10, 640, 480));
        display_screen->setAutoFillBackground(true);
        display_screen->setFrameShape(QFrame::WinPanel);
        display_screen->setFrameShadow(QFrame::Raised);
        display_screen->setLineWidth(4);
        display_screen->setMidLineWidth(4);
        display_screen->setMargin(0);
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 500, 341, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        film_Button = new QPushButton(horizontalLayoutWidget);
        film_Button->setObjectName(QStringLiteral("film_Button"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("obrazy/movie_clapboard_cinema_clapper_studio_equipment_flat_icon_symbol-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        film_Button->setIcon(icon1);
        film_Button->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(film_Button);

        kamera_Button = new QPushButton(horizontalLayoutWidget);
        kamera_Button->setObjectName(QStringLiteral("kamera_Button"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("obrazy/webcam-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        kamera_Button->setIcon(icon2);
        kamera_Button->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(kamera_Button);

        zdjecie_Button = new QPushButton(horizontalLayoutWidget);
        zdjecie_Button->setObjectName(QStringLiteral("zdjecie_Button"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("obrazy/camera-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        zdjecie_Button->setIcon(icon3);
        zdjecie_Button->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(zdjecie_Button);

        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(380, 500, 151, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wykrywanie_Button = new QPushButton(verticalLayoutWidget);
        wykrywanie_Button->setObjectName(QStringLiteral("wykrywanie_Button"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("obrazy/017-turn-right-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        wykrywanie_Button->setIcon(icon4);
        wykrywanie_Button->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(wykrywanie_Button);

        stop_Button = new QPushButton(verticalLayoutWidget);
        stop_Button->setObjectName(QStringLiteral("stop_Button"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setItalic(true);
        stop_Button->setFont(font);
        stop_Button->setLayoutDirection(Qt::LeftToRight);
        stop_Button->setAutoFillBackground(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral("obrazy/039-no-entry.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop_Button->setIcon(icon5);
        stop_Button->setIconSize(QSize(40, 40));
        stop_Button->setCheckable(false);
        stop_Button->setAutoDefault(true);
        stop_Button->setFlat(false);

        verticalLayout->addWidget(stop_Button);

        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(670, 11, 301, 601));
        tableWidget->setFrameShape(QFrame::WinPanel);
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setTextElideMode(Qt::ElideLeft);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        frame_counter = new QLabel(Dialog);
        frame_counter->setObjectName(QStringLiteral("frame_counter"));
        frame_counter->setGeometry(QRect(540, 500, 121, 41));
        horizontalSlider = new QSlider(Dialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(50, 650, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(Dialog);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(50, 690, 160, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(Dialog);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(50, 730, 160, 22));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(Dialog);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(240, 650, 160, 22));
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(Dialog);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setGeometry(QRect(240, 690, 160, 22));
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        ok = new QPushButton(Dialog);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(270, 730, 75, 23));

        retranslateUi(Dialog);

        stop_Button->setDefault(false);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Traffic Sign Recognition", nullptr));
        display_screen->setText(QString());
        film_Button->setText(QApplication::translate("Dialog", "Film", nullptr));
        kamera_Button->setText(QApplication::translate("Dialog", "Kamera", nullptr));
        zdjecie_Button->setText(QApplication::translate("Dialog", "Zdj\304\231cie", nullptr));
        wykrywanie_Button->setText(QApplication::translate("Dialog", "Wykrywaj Znaki", nullptr));
        stop_Button->setText(QApplication::translate("Dialog", "STOP", nullptr));
        frame_counter->setText(QString());
        ok->setText(QApplication::translate("Dialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
