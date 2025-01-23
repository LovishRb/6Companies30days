class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;

        int i = 0, n = directions.size();

        while (i < n && directions[i] == 'L') i++;
        while (n > 0 && directions[n - 1] == 'R') n--;

        
        while (i < n) {
            if (directions[i] != 'S') {
                count++;
            }
            i++;
        }
        
        return count;
    }
};