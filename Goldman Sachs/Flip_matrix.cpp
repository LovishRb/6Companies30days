class Solution {
public:
    int row,col;
    set<pair<int,int>> s;
    Solution(int m, int n) {
        row = m;col = n;
    }
    
    vector<int> flip() {
        int index = rand() %(row* col);
        int r = index / col;
        int c = index % col;

        if(s.find({r,c}) == s.end()){
            s.insert({r,c});
            return {r,c};
        }
        else{
            return flip();
        }
        
    }
    
    void reset() {
        s.clear();
    }
};

