class TrieNode {
public:
    TrieNode *child[26];
    bool isWord{false};
    TrieNode() {
        for(auto &n: child) n = nullptr;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *nd = root;
        for(char c : word){
            if(!nd->child[c - 'a'])
                nd->child[c - 'a'] = new TrieNode();
            nd = nd->child[c - 'a'];
        }
        nd->isWord = true;
    }

    TrieNode* find(string word) {
        TrieNode *nd = root;
        for(char c : word){
            if(nd->child[c - 'a'] == nullptr) return nullptr;
            nd = nd->child[c - 'a'];
        }
        return nd;
    }

    bool search(string word) {
        TrieNode *nd = find(word);
        return nd == nullptr ? false : nd->isWord;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) == nullptr ? false : true;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */