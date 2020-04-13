#include "Trie.h"
#include <algorithm>

bool isLetter(unsigned char c) {
    return c != ' ';
}

void Trie::AddWord(const std::string& s) {
    if (s.empty()) {
        return;
    }
    Node* now = root_;
    for (unsigned char c: s) {
        if (now->children[c] == nullptr) {
            now->children[c] = new Node();
            now->children[c]->parent_ = now;
            now->children[c]->parent_symbol_ = c;
        }
        now = now->children[c];
    }
    now->terminal_count_++;
    if (now->max_word_node_ == nullptr) {
        now->max_word_node_ = now;
    }
    Node* back = now;
    while (back != root_) {
        if (back->max_word_count_ >= now->terminal_count_) {
            break;
        }
        back->max_word_count_ = now->terminal_count_;
        back->max_word_node_ = now->max_word_node_;
        back = back->parent_;
    }
}

void Trie::AddText(const std::string& s) {
    std::string now_word;
    for (char i : s) {
        if (!isLetter(i)) {
            AddWord(now_word);
            now_word.clear();
        } else {
            now_word += i;
        }
    }
    AddWord(now_word);
}

Trie::Trie(const std::string& text) : Trie() {
    AddText(text);
}

Trie::Trie() : last_request_(nullptr) {
    root_ = new Node();
}

void Trie::Request(const std::string& word) {
    last_request_ = root_;
    AddToPreviousRequest(word);
}

std::string Trie::GetCompletion() {
    if (last_request_ == nullptr) {
        return std::string();
    }
    Node* word = last_request_->max_word_node_;
    std::string result;
    while (word != root_) {
        result += word->parent_symbol_;
        word = word->parent_;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void Trie::AddToPreviousRequest(const std::string& word) {
    for (unsigned char c: word) {
        if (last_request_ == nullptr) {
            return;
        }
        last_request_ = last_request_->children[c];
    }
}

Trie::Node::Node() : terminal_count_(0), max_word_count_(0), max_word_node_(nullptr), parent_(nullptr),
                     parent_symbol_('\0') {}
