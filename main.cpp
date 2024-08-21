#include <iostream>
#include <string>

// Универсальная функция для шифрования и расшифровки текста по методу Цезаря
std::string caesar_cipher(const std::string &text, int shift) {
    std::string result;
    shift = shift % 26; // Приведение значения shift к допустимому диапазону [-25, 25]

    for (char c : text) {
        if ('a' <= c && c <= 'z') {
            // Сдвиг для строчных букв
            char encrypted_char = static_cast<char>('a' + (c - 'a' + shift + 26) % 26);
            result += encrypted_char;
        } else if ('A' <= c && c <= 'Z') {
            // Сдвиг для заглавных букв
            char encrypted_char = static_cast<char>('A' + (c - 'A' + shift + 26) % 26);
            result += encrypted_char;
        } else {
            // Другие символы остаются без изменений
            result += c;
        }
    }

    return result;
}

// Функция для расшифровки текста методом brute-force
void brute_force_caesar(const std::string &text) {
    std::cout << "Результаты brute-force:" << std::endl;
    for (int shift = 1; shift < 26; ++shift) {
        std::cout << "Shift " << shift << ": " << caesar_cipher(text, -shift) << std::endl;
    }
}

int main() {
    std::string text;
    int shift;
    int choice;

    // Ввод текста пользователем
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    // Запрос действия у пользователя
    std::cout << "Выберите действие:\n1 - Зашифровать текст\n2 - Расшифровать текст\n3 - Применить brute-force\nВаш выбор: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Введите сдвиг для шифрования (может быть отрицательным): ";
        std::cin >> shift;
        std::string encrypted_text = caesar_cipher(text, shift);
        std::cout << "Зашифрованный текст: " << encrypted_text << std::endl;
    } else if (choice == 2) {
        std::cout << "Введите сдвиг для расшифровки (может быть отрицательным): ";
        std::cin >> shift;
        std::string decrypted_text = caesar_cipher(text, -shift);
        std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;
    } else if (choice == 3) {
        brute_force_caesar(text);
    } else {
        std::cout << "Неверный выбор. Программа завершена." << std::endl;
    }

    return 0;
}