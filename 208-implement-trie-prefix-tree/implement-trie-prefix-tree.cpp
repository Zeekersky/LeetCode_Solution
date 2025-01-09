struct Node{
    Node* letter[26];
    bool isEnd;
    
    Node() {
        for (int i = 0; i < 26; ++i) {
            letter[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->letter[word[i]-'a'] == nullptr)
                node->letter[word[i]-'a'] = new Node();
            node = node->letter[word[i]-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->letter[word[i]-'a']!=NULL)
                node = node->letter[word[i]-'a'];
            else return false;
        }
        if(!node->isEnd) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(node->letter[prefix[i]-'a']!=NULL)
                node = node->letter[prefix[i]-'a'];
            else return false;
        }
        if(!node) return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */