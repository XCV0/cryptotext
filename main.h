/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_H
#define MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowMain
{
public:
    QWidget *centralwidget;
    QPushButton *decrypt_mode_btn;
    QPushButton *encrypt_mode_btn;
    QTextEdit *toEncrypt_entry;
    QLabel *label;
    QTextEdit *decryptKey_entry;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowMain)
    {
        if (WindowMain->objectName().isEmpty())
            WindowMain->setObjectName(QString::fromUtf8("WindowMain"));
        WindowMain->resize(480, 660);
        centralwidget = new QWidget(WindowMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        decrypt_mode_btn = new QPushButton(centralwidget);
        decrypt_mode_btn->setObjectName(QString::fromUtf8("decrypt_mode_btn"));
        decrypt_mode_btn->setEnabled(true);
        decrypt_mode_btn->setGeometry(QRect(115, 70, 261, 51));
        encrypt_mode_btn = new QPushButton(centralwidget);
        encrypt_mode_btn->setObjectName(QString::fromUtf8("encrypt_mode_btn"));
        encrypt_mode_btn->setEnabled(true);
        encrypt_mode_btn->setGeometry(QRect(115, 20, 261, 51));
        toEncrypt_entry = new QTextEdit(centralwidget);
        toEncrypt_entry->setObjectName(QString::fromUtf8("toEncrypt_entry"));
        toEncrypt_entry->setGeometry(QRect(10, 200, 461, 71));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 451, 71));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        decryptKey_entry = new QTextEdit(centralwidget);
        decryptKey_entry->setObjectName(QString::fromUtf8("decryptKey_entry"));
        decryptKey_entry->setGeometry(QRect(10, 310, 461, 71));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 280, 301, 21));
        label_2->setAlignment(Qt::AlignCenter);
        WindowMain->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WindowMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WindowMain->setStatusBar(statusbar);

        retranslateUi(WindowMain);

        QMetaObject::connectSlotsByName(WindowMain);
    } // setupUi

    void retranslateUi(QMainWindow *WindowMain)
    {
        WindowMain->setWindowTitle(QCoreApplication::translate("WindowMain", "Crypto Text", nullptr));
        decrypt_mode_btn->setText(QCoreApplication::translate("WindowMain", "Decrypt", nullptr));
        encrypt_mode_btn->setText(QCoreApplication::translate("WindowMain", "Encrypt", nullptr));
        toEncrypt_entry->setMarkdown(QString());
        toEncrypt_entry->setHtml(QCoreApplication::translate("WindowMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        toEncrypt_entry->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("WindowMain", "Enter Encrypted text or text for Encrypt", nullptr));
        decryptKey_entry->setMarkdown(QString());
        decryptKey_entry->setHtml(QCoreApplication::translate("WindowMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        decryptKey_entry->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("WindowMain", "Key for decrypt(if need)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowMain: public Ui_WindowMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_H
