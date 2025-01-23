class WordDictionary {
public:

    unordered_map<int,vector<string>> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool solve(string& word, string& candidate) {
        //     // to check if the words size is greater than finding the size of string
    //     // to optimize we use map which contains the size of word and vector of string that conatins same sized words...
         //   if(s.size() > x.size())return false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != '.' && word[i] != candidate[i]) {
                return false;
            }
        }
        return true;
    }
    bool search(string word) {
        // Check only words with the same size
        if (mp.find(word.size()) == mp.end()) return false;

        for (string& candidate : mp[word.size()]) {
            if (solve(word, candidate)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */