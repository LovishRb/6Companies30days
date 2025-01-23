class Solution {
private:
    vector<int> solve(TreeNode* root , int distance){


        if(!root) return vector<int>(12);
        else if (!root->left && !root->right){
            vector<int> dist(12);
            dist[0] = 1;// it means out root is already a leaf node so the count of leaf node at index 0 is 1;
            return dist;
        }
        vector<int> dist(12);
        vector<int> left = solve(root->left,distance);
        vector<int> right = solve(root->right,distance);

        // combined result by shifting the distance to right by 1;

        for(int i = 0 ;i<10;i++){
            dist[i+1] = left[i] + right[i];
        }

        dist[11] += left[11] + right[11];

        // check all good pairs;

        for(int d1 = 0 ;d1<=distance;d1++){
            for(int d2 = 0;d2<=distance ;d2++){
                if( d1 + d2 +2 <= distance)dist[11] += left[d1] * right[d2];
            }
        }

        return dist;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        return solve(root,distance)[11];
    }
};