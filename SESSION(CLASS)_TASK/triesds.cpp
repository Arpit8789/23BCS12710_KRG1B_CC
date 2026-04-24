#include <iostream>
#include <string>
using namespace std;

// Trie Node structure
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie
    void insert(string key) {
        TrieNode* current = root;
        
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        
        current->isEndOfWord = true;
    }
    
    // Search for a word in the Trie
    bool search(string key) {
        TrieNode* current = root;
        
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        
        return (current != nullptr && current->isEndOfWord);
    }
    
    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;
        
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        
        return true;
    }
    
    // Delete a word from the Trie
    bool deleteWord(TrieNode* current, string key, int depth) {
        if (current == nullptr) {
            return false;
        }
        
        if (depth == key.length()) {
            if (current->isEndOfWord) {
                current->isEndOfWord = false;
            }
            
            // Check if current node has any children
            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    return false;
                }
            }
            return true;
        }
        
        int index = key[depth] - 'a';
        if (deleteWord(current->children[index], key, depth + 1)) {
            delete current->children[index];
            current->children[index] = nullptr;
            
            // Check if current node can be deleted
            return !current->isEndOfWord && 
                   allOfChildrenNull(current->children, 26);
        }
        
        return false;
    }
    
    void deleteWord(string key) {
        deleteWord(root, key, 0);
    }
    
private:
    bool allOfChildrenNull(TrieNode* children[], int size) {
        for (int i = 0; i < size; i++) {
            if (children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
};

// Main function to demonstrate Trie operations
int main() {
    Trie trie;
    
    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("ban");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bandana");
    
    // Search operations
    cout << "Search Operations:" << endl;
    cout << "apple -> " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "app -> " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "appl -> " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "banana -> " << (trie.search("banana") ? "Found" : "Not Found") << endl;
    
    // Prefix search
    cout << "\nPrefix Operations:" << endl;
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "Yes" : "No") << endl;
    cout << "Starts with 'cat': " << (trie.startsWith("cat") ? "Yes" : "No") << endl;
    
    // Delete a word
    cout << "\nDelete Operation:" << endl;
    trie.deleteWord("app");
    cout << "After deleting 'app':" << endl;
    cout << "app -> " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "apple -> " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    
    return 0;
}
