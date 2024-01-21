#include <iostream>
#include <iomanip>
#include <locale>
#include <codecvt>
#include <string>
#include <sstream>
#include <random>
#include "main.h"

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QObject>



using namespace std;

std::pair<std::string, int> EncryptText(std::string text) {
    std::string _encryptedmsg;
    int EKey;

    // generate random number (byteshift)
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist6(1, 99); // generate number [1, 99]

    int byteshift = dist6(rng); // generate byteshift
    cout << "[DEBUG] generated byte shift: " << byteshift << std::endl; // cout byteshift

    for (char symbol : text) {
        if (symbol == ',' || symbol == '.' || symbol == ' ' || symbol == '!') {
            _encryptedmsg += symbol;
            continue;
        }

        // Convert the symbol to its UTF-32 representation
        wstring_convert<codecvt_utf8_utf16<char32_t>, char32_t> converter;
        u32string utf32 = converter.from_bytes(&symbol, &symbol + 1);

        // Convert the UTF-32 representation to UTF-8
        string utf8 = converter.to_bytes(utf32);

        // Output the UTF-8 representation
        for (unsigned char c : utf8) {
            ostringstream hexstring;
            int hexValue = static_cast<int>(c) + byteshift; // add byteshift
            hexstring << hex << std::setfill('0') << std::setw(2) << hexValue;
            _encryptedmsg += hexstring.str(); // add hexsymbol to hexstring
        }
    }

    cout << "KEY: " << byteshift << endl;

    return std::make_pair(_encryptedmsg, byteshift);
}

string DecryptText(const string& encryptedText, int EKey) {
    string decryptedMsg;

    for (size_t i = 0; i < encryptedText.length(); i ++) {
        if ((encryptedText[i] == '!' || encryptedText[i] == ',' || encryptedText[i] == ' ') && i != encryptedText.length()) {
            decryptedMsg += encryptedText[i];
            continue;
        }

        // Извлекаем каждый символ HEX и конвертируем его в число
        string hexSymbol = encryptedText.substr(i, 2);
        istringstream hexStream(hexSymbol);
        int hexValue;
        hexStream >> hex >> hexValue;

        // Вычитаем обратный сдвиг
        char decryptedChar = static_cast<char>(hexValue - EKey);

        // Добавляем символ к расшифрованному тексту
        decryptedMsg += decryptedChar;
        i++;
    }

    return decryptedMsg;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    Ui::WindowMain ui; // Assuming you have generated the Ui namespace using Qt Designer

    mainWindow.setMinimumSize(480, 660);
    mainWindow.setMaximumSize(480, 660); 

    ui.setupUi(&mainWindow); // Setup the UI

    // Connect your buttons to slots (functions) here
    QObject::connect(ui.encrypt_mode_btn, &QPushButton::clicked, [&]() {
    QString text = ui.toEncrypt_entry->toPlainText();
    auto encryptionResult = EncryptText(text.toStdString());

    ui.toEncrypt_entry->setPlainText(QString::fromStdString(encryptionResult.first));

    // Автоматически устанавливаем значение EKey в decryptKey_entry
    ui.decryptKey_entry->setPlainText(QString::number(encryptionResult.second));
    });


    QObject::connect(ui.decrypt_mode_btn, &QPushButton::clicked, [&]() {
    QString encryptedText = ui.toEncrypt_entry->toPlainText();
    int key = ui.decryptKey_entry->toPlainText().toInt();

    // Передаем значение EKey в функцию DecryptText
    QString decryptedText = QString::fromStdString(DecryptText(encryptedText.toStdString(), key));
    ui.toEncrypt_entry->setPlainText(decryptedText);
    });


    // Connect other buttons and functionality as needed

    mainWindow.show();
    
    return app.exec();
}


