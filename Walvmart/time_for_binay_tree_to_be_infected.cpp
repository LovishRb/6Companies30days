class Solution {
public:
    vector<vector<int>> build_graph(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) return ans; 
        
        int maxNodeValue = find_max_value(root);

        
        ans.resize(maxNodeValue + 1);

        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            int curr_val = curr->val;

            if (curr->left) {
                ans[curr_val].push_back(curr->left->val);
                ans[curr->left->val].push_back(curr_val);
                q.push(curr->left);
            }
            if (curr->right) {
                ans[curr_val].push_back(curr->right->val);
                ans[curr->right->val].push_back(curr_val);
                q.push(curr->right);
            }
        }

        return ans;
    }

    
    int find_max_value(TreeNode* root) {
        if (!root) return 0;
        return max({root->val, find_max_value(root->left), find_max_value(root->right)});
    }

    int amountOfTime(TreeNode* root, int start) {
        
        vector<vector<int>> ans = build_graph(root);

        
        int minutes = -1; // Start at -1 to account for the last BFS level
        queue<int> q;
        vector<bool> visited(ans.size(), false);

        
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int st = q.front();
                q.pop();

                
                for (int x : ans[st]) {
                    if (!visited[x]) {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
            minutes++; 
        }

        return minutes;
    }
};
