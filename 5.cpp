/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class WordDictionary {
    unordered_map<int,vector<string>> wordmap;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        wordmap[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(wordmap.find(word.size())==wordmap.end())
            return false;
        bool ret = false;
        for(string w:wordmap[word.size()])
        {
            bool matched = true;
            for(int i=0;i<w.size();i++)
            {
                if(word[i]=='.')
                    continue;
                if(w[i]!=word[i])
                {
                    matched = false;
                    break;
                }
            }
            if(matched)
            {
                ret = true;
                break;
            }
        }
        return ret;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
