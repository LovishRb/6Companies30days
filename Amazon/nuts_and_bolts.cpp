class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        map<char,int> mp ={
            {'!',9},
            {'#',8},
            {'$',7},
            {'%',6},
            {'&',5},
            {'*',4},
            {'?',3},
            {'@',2},
            {'^',1}
        };
        
        
        unordered_map<char,int> m1;
        for(int i =0;i<n;i++)m1[nuts[i]]++;
        
        int j =0;
        for(auto it : mp){
            // cout<<"key " << it.first<<endl;
            if(m1.find(it.first) != m1.end()){
                // cout<<"key found " << it.first<<endl;
                nuts[j]=it.first;
                bolts[j]=it.first;
                j++;
            }
        }
    }
};