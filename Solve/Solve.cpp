
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
            std::cout << "New request: \"" << request_string << "\"\n";
            std::cout << "Suggested completion: \"" << trie_.GetCompletion() << "\"\n\n";
        } else if (op_char == 't') {
            std::string text;
            getline(std::cin, text);
            std::cout << "Text to add: \"" << text << "\"\n\n";
            trie_.AddText(text);
        } else if (op_char == '+') {
            std::string add_string;
            std::cin >> add_string;
            trie_.AddToPreviousRequest(add_string);
            std::cout << "Symbols to add to previous requests and adds: \"" << add_string << "\"\n\n";
            std::cout << "Suggested completion: \"" << trie_.GetCompletion() << "\"\n\n";
        } else {
            std::cout << "Unknown operation\n\n";
        }
    }
}
