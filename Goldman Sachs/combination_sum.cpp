class Solution {
public:
    void solve(int index , int k , int n,vector<int>& arr,vector<vector<int>>& ans,vector<int>& res){
        // vector<vector<int>> ans;

        if(res.size() == k && n== 0){
            ans.push_back(res);
            return ;
        }

        if(index >=arr.size())return ;

        // add to vector
        res.push_back(arr[index]);
        solve(index + 1 , k , n-arr[index],arr,ans,res);

        // to backtrack;
        res.pop_back();

        solve(index + 1, k , n , arr,ans,res);


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> res;
        vector<vector<int>> ans;
        solve(0,k,n,arr,ans,res);
        return ans;
    }
};