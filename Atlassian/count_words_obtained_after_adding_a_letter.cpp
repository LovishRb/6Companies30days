class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> startSet;

        // Process startWords to store their sorted versions in a set
        for (string word : startWords) {
            sort(word.begin(), word.end());
            startSet.insert(word);
        }

        int count = 0;

        // Process targetWords to check if they can be reduced to a word in startSet
        for (string word : targetWords) {
            sort(word.begin(), word.end());
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                temp.erase(i, 1); // Remove the i-th character
                if (startSet.find(temp) != startSet.end()) {
                    count++;
                    break; // Move to the next targetWord as this one matches
                }
            }
        }

        return count;
    }
};