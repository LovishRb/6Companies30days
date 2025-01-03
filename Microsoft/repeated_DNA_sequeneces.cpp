class Solution {
public:
    long long hash_function(string const& s,unordered_map<char,int>& char_int_map , int length_substr){

        int p = 5;
        int m = 1e9 +  9;
        long long curr_hash_value = 0;
        long long pow = 1;// power

        for(int i =0;i<length_substr;i++){
            curr_hash_value = (curr_hash_value + char_int_map[s[i]] * pow) % m;
            pow = (pow * p) % m;
        }
        return curr_hash_value;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int window_size = 10;
        
        if(s.length() < window_size)return result;


        // set to store unique hashes of substring of given window
        unordered_set<int> hashes_of_substr;
        
        // set to store the unique repeated sequences that satisfies the given condition
        unordered_set<string> repeated_sequence;
        
        // map to store a mapping index of character into integer
        unordered_map<char,int> char_int_map = {
            {'A',0},
            {'C',1},
            {'G',2},
            {'T',3}
        };

        for(int i =0;i+10<=s.length() ; i++){
            string str = s.substr(i,10);

            // compute hash for this string
            long long hash = hash_function(str,char_int_map,10);

            if(hashes_of_substr.find(hash) != hashes_of_substr.end()){
                repeated_sequence.insert(str);
            }
            else{
                hashes_of_substr.insert(hash);
            }

        }
        result.assign(repeated_sequence.begin(),repeated_sequence.end());
        return result;
    }
};