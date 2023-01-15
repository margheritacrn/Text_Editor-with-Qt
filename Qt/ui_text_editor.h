/********************************************************************************
** Form generated from reading UI file 'text_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXT_EDITOR_H
#define UI_TEXT_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Text_Editor
{
public:
    QAction *actionNuovo;
    QAction *actionApri;
    QAction *actionSalva;
    QAction *actionSalva_con_nome;
    QAction *actionEsci;
    QAction *actionCerca_stringa;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSearch;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Text_Editor)
    {
        if (Text_Editor->objectName().isEmpty())
            Text_Editor->setObjectName(QString::fromUtf8("Text_Editor"));
        Text_Editor->resize(810, 603);
        actionNuovo = new QAction(Text_Editor);
        actionNuovo->setObjectName(QString::fromUtf8("actionNuovo"));
        actionNuovo->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNuovo->setIcon(icon);
        actionApri = new QAction(Text_Editor);
        actionApri->setObjectName(QString::fromUtf8("actionApri"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionApri->setIcon(icon1);
        actionSalva = new QAction(Text_Editor);
        actionSalva->setObjectName(QString::fromUtf8("actionSalva"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icon_save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalva->setIcon(icon2);
        actionSalva_con_nome = new QAction(Text_Editor);
        actionSalva_con_nome->setObjectName(QString::fromUtf8("actionSalva_con_nome"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Save-as-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalva_con_nome->setIcon(icon3);
        actionEsci = new QAction(Text_Editor);
        actionEsci->setObjectName(QString::fromUtf8("actionEsci"));
        actionCerca_stringa = new QAction(Text_Editor);
        actionCerca_stringa->setObjectName(QString::fromUtf8("actionCerca_stringa"));
        actionCerca_stringa->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCerca_stringa->setIcon(icon4);
        centralwidget = new QWidget(Text_Editor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 10, 811, 591));
        Text_Editor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Text_Editor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 810, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSearch = new QMenu(menubar);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        Text_Editor->setMenuBar(menubar);
        statusbar = new QStatusBar(Text_Editor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Text_Editor->setStatusBar(statusbar);
        toolBar = new QToolBar(Text_Editor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Text_Editor->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSearch->menuAction());
        menuFile->addAction(actionNuovo);
        menuFile->addSeparator();
        menuFile->addAction(actionApri);
        menuFile->addSeparator();
        menuFile->addAction(actionSalva);
        menuFile->addSeparator();
        menuFile->addAction(actionSalva_con_nome);
        menuFile->addSeparator();
        menuFile->addAction(actionEsci);
        menuFile->addSeparator();
        menuSearch->addAction(actionCerca_stringa);
        toolBar->addAction(actionNuovo);
        toolBar->addAction(actionApri);
        toolBar->addAction(actionSalva);
        toolBar->addAction(actionSalva_con_nome);
        toolBar->addAction(actionCerca_stringa);

        retranslateUi(Text_Editor);
        QObject::connect(actionEsci, SIGNAL(triggered()), Text_Editor, SLOT(close()));

        QMetaObject::connectSlotsByName(Text_Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Text_Editor)
    {
        Text_Editor->setWindowTitle(QCoreApplication::translate("Text_Editor", "Text_Editor", nullptr));
        actionNuovo->setText(QCoreApplication::translate("Text_Editor", "Nuovo", nullptr));
        actionApri->setText(QCoreApplication::translate("Text_Editor", "Apri", nullptr));
        actionSalva->setText(QCoreApplication::translate("Text_Editor", "Salva", nullptr));
        actionSalva_con_nome->setText(QCoreApplication::translate("Text_Editor", "Salva con nome", nullptr));
        actionEsci->setText(QCoreApplication::translate("Text_Editor", "Esci", nullptr));
        actionCerca_stringa->setText(QCoreApplication::translate("Text_Editor", "Cerca stringa", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Text_Editor", "File", nullptr));
        menuSearch->setTitle(QCoreApplication::translate("Text_Editor", "Cerca ", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Text_Editor", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Text_Editor: public Ui_Text_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXT_EDITOR_H
