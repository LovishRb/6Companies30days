class Solution {
private:
    void solve(string digits,vector<string> &ans,string *mapping,int i , string output){
        // base case
        if(i >=digits.size()){
            ans.push_back(output);
            return ;
        }
        int number=digits[i]-'0';
        string val=mapping[number];
        for(int j =0;j<val.size();j++){
            output.push_back(val[j]);
            solve(digits,ans,mapping,i+1,output);

            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


        string output;

        int index=0;

        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        solve(digits,ans,mapping,index,output);
        return ans;
    }
};