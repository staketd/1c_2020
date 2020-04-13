
#include "Solve.h"
#include <iostream>

Solve::Solve() : trie_() {}

void Solve::Start() {
    char op_char;
    while (std::cin >> op_char) {
        if (op_char == '!') {
            break;
        }
        if (op_char == '?') {
            std::string request_string;
            std::cin >> request_string;
            trie_.Request(request_string);
            std::cout << "Запрос: \"" << request_string << "\"\n";
            std::cout << "Подсказка: \"" << trie_.GetCompletion() << "\"\n\n";
        } else if (op_char == 't') {
            std::string text;
            getline(std::cin, text);
            std::cout << "Добавленный текст: \"" << text << "\"\n\n";
            trie_.AddText(text);
        } else if (op_char == '+') {
            std::string add_string;
            std::cin >> add_string;
            trie_.AddToPreviousRequest(add_string);
            std::cout << "Добавленные символы: \"" << add_string << "\"\n\n";
            std::cout << "Подсказка: \"" << trie_.GetCompletion() << "\"\n\n";
        } else {
            std::cout << "Неизвестная операция\n\n";
        }
    }
}
