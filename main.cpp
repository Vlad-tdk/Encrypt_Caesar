#include <iostream>
#include <string>

// Функция для шифрования текста по методу Цезаря
std::string encrypt_caesar(const std::string &text, int shift) {
    std::string result;

    // Приведение значения shift к допустимому диапазону 0-25
    shift = shift % 26;

    for (char c : text) {
        if ('a' <= c && c <= 'z') {  // для строчных букв
            int temp = (c - 'a' + shift) % 26 + 'a';
            result += static_cast<char>(temp);
        } else if ('A' <= c && c <= 'Z') {  // для заглавных букв
            int temp = (c - 'A' + shift) % 26 + 'A';
            result += static_cast<char>(temp);
        } else {  // другие символы оставляем без изменений
            result += c;
        }
    }

    return result;
}

// Функция для расшифровки текста по методу Цезаря
std::string decrypt_caesar(const std::string &text, int shift) {
    std::string result;

    // Приведение значения shift к допустимому диапазону 0-25
    shift = shift % 26;

    for (char c : text) {
        if ('a' <= c && c <= 'z') {  // для строчных букв
            int temp = (c - 'a' - shift + 26) % 26 + 'a';
            result += static_cast<char>(temp);
        } else if ('A' <= c && c <= 'Z') {  // для заглавных букв
            int temp = (c - 'A' - shift + 26) % 26 + 'A';
            result += static_cast<char>(temp);
        } else {  // другие символы оставляем без изменений
            result += c;
        }
    }

    return result;
}

// Функция для расшифровки методом грубой силы
void brute_force_decrypt(const std::string &text) {
    for (int shift = 1; shift < 26; ++shift) {
        std::string decrypted_text = decrypt_caesar(text, shift);
        std::cout << "Сдвиг " << shift << ": " << decrypted_text << std::endl;
    }
}

int main() {
    std::string text;
    int choice;

    // Ввод текста пользователем
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    std::cout << "Выберите действие (1 - зашифровать, 2 - расшифровать, 3 - расшифровать методом грубой силы): ";
    std::cin >> choice;

    if (choice == 1) {
        int shift;
        std::cout << "Введите сдвиг: ";
        std::cin >> shift;
        std::string encrypted_text = encrypt_caesar(text, shift);
        std::cout << "Зашифрованный текст: " << encrypted_text << std::endl;
    } else if (choice == 2) {
        int shift;
        std::cout << "Введите сдвиг: ";
        std::cin >> shift;
        std::string decrypted_text = decrypt_caesar(text, shift);
        std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;
    } else if (choice == 3) {
        std::cout << "Попытка расшифровки методом грубой силы..." << std::endl;
        brute_force_decrypt(text);
    } else {
        std::cout << "Некорректный выбор!" << std::endl;
        return 1;
    }

    return 0;
}
