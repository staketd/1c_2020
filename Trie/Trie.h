
#ifndef INC_1C_TRIE_H
#define INC_1C_TRIE_H

#include <map>

class Trie {
public:
    void AddText(const std::string& s);
    void Request(const std::string& word);

    std::string GetCompletion();
    void AddToPreviousRequest(const std::string& word);
    
    explicit Trie(const std::string& text);
    Trie();

private:
    void AddWord(const std::string& s);

    struct Node {
        Node();

        std::map<char, Node*> children;
        size_t terminal_count_;
        size_t max_word_count_;
        Node* max_word_node_;
        Node* parent_;
        char parent_symbol_;
    };
    Node* root_;
    Node* last_request_;
};


#endif //INC_1C_TRIE_H
