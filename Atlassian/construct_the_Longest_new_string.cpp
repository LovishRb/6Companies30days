class Solution {
public:
    int longestString(int x, int y, int z) {
        // z does not matter it will always add all the values of z 
        if(x == y)return 2*(x+y+z);
        else return 2*(z + 2*min(x,y) + 1);
    }
};