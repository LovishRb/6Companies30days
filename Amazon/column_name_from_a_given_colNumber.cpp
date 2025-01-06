class Solution {
public:
    string convertToTitle(int columnNumber) {
        string temp ="";
        while(columnNumber){
            columnNumber--;
            int mod = columnNumber%26;
            char c = mod + 'A' ;
            temp+= c;
            columnNumber = columnNumber / 26;
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};