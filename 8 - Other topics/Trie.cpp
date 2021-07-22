class Trie {
private:
    struct TrieNode{
        
        bool isWord;
        unordered_map<char,TrieNode*> children;
        
        TrieNode(){
            isWord = false;
        }
    };
    
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();    
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode* curr = root;
        
        for(char ch:word)
        {
            if(curr->children.count(ch))
            {
                curr = curr->children[ch];
            }else
            {
                curr->children[ch] = new TrieNode();
                curr = curr->children[ch];
            }
        }
        curr->isWord = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        
        for(char ch:word)
        {
            if(curr->children.count(ch)==0)
                return false;
            curr = curr->children[ch];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(char ch:prefix)
        {
            if(curr->children.count(ch)==0)
                return false;
            curr = curr->children[ch];
        }
        return true;
    }
};
