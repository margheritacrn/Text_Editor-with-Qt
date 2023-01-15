/********************************************************************************
** Form generated from reading UI file 'search_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_DIALOG_H
#define UI_SEARCH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search_dialog
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QLabel *error_label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *find_button;
    QPushButton *close;

    void setupUi(QDialog *search_dialog)
    {
        if (search_dialog->objectName().isEmpty())
            search_dialog->setObjectName(QString::fromUtf8("search_dialog"));
        search_dialog->resize(436, 213);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        search_dialog->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(search_dialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(90, 60, 305, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        checkBox = new QCheckBox(horizontalLayoutWidget_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setFont(font);

        verticalLayout_2->addWidget(checkBox);

        error_label = new QLabel(horizontalLayoutWidget_2);
        error_label->setObjectName(QString::fromUtf8("error_label"));
        error_label->setEnabled(false);
        error_label->setVisible(false);
        QPalette palette = error_label->palette();
                palette.setColor(QPalette::WindowText, "red");
                error_label->setPalette(palette);

        verticalLayout_2->addWidget(error_label);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        find_button = new QPushButton(horizontalLayoutWidget_2);
        find_button->setObjectName(QString::fromUtf8("find_button"));
        find_button->setEnabled(false);
        find_button->setFont(font);

        verticalLayout->addWidget(find_button);

        close = new QPushButton(horizontalLayoutWidget_2);
        close->setObjectName(QString::fromUtf8("close"));
        close->setFont(font);

        verticalLayout->addWidget(close);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(search_dialog);
        QObject::connect(close, SIGNAL(clicked()), search_dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(search_dialog);
    } // setupUi

    void retranslateUi(QDialog *search_dialog)
    {
        search_dialog->setWindowTitle(QCoreApplication::translate("search_dialog", "Find", nullptr));
        label->setText(QCoreApplication::translate("search_dialog", "Find What", nullptr));
        checkBox->setText(QCoreApplication::translate("search_dialog", "Match case", nullptr));
        error_label->setText(QCoreApplication::translate("search_dialog", "Nessuna occorrenza trovata", nullptr));
        find_button->setText(QCoreApplication::translate("search_dialog", "find", nullptr));
        close->setText(QCoreApplication::translate("search_dialog", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search_dialog: public Ui_search_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_DIALOG_H
