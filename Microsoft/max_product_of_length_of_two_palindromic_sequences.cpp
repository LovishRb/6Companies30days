class Solution {
public:
    int max_product =0;
    bool isPalindrome(string s){
        string rev = s;
        reverse(rev.begin(),rev.end());

        
        for(int i =0;i<s.length();i++){
            if(s[i] != rev[i])
                return false;
        }

        return true;
    }

    void backtrack(string& s ,string& a,string& b,int index){
        // base case
        if(index >= s.length()){
            if(isPalindrome(a) && isPalindrome(b))
            {
                max_product = max(max_product , (int)a.length() * (int) b.length());
            }
            return;
        }

        // first option is to insert the character to string a;

        a.push_back(s[index]);
        backtrack(s,a,b,index+1);
        a.pop_back();

        // Second option is to insert the character to string b;

        b.push_back(s[index]);
        backtrack(s,a,b,index+1);
        b.pop_back();

        // first option is to insert the character to string 1;

        backtrack(s,a,b,index+1);

    }
    int maxProduct(string s) {
        string s1="";
        string s2 = "";
        backtrack(s,s1,s2,0);
        return max_product;
    }
};