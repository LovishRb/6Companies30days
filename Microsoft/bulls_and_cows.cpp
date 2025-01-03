class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        vector<bool> visited(guess.size(),false);
        for(char c : secret)mp[c]++;
        int bulls =0;
        int cows = 0;
        for(int i =0;i<guess.size();i++){
            // if(mp[guess[i]] > 0){
            //     mp[guess[i]]--;
            //     if(guess[i] == secret[i])bulls++;
            //     else cows++;

            // }
            if(guess[i] == secret[i]){
                mp[guess[i]]--;
                bulls++;
                visited[i] = true;
            }

        }
        for(int i =0;i<guess.size();i++){
            cout<<mp[guess[i]]<<endl;
            if(mp[guess[i]] > 0 && !visited[i]){
                cows++;
                mp[guess[i]]--;
            }
        }

        string temp =to_string(bulls) + "A" + to_string(cows) + "B";
        return temp;
    }
};