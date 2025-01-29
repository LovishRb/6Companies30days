class Solution {
public:
    int solve(int node ,vector<vector<int>>&dist,int n){
        int cnt_node=0,cnt_edge=0,max_dist =0;

        for(int i =0;i<n;i++){
            if(((node >> i)&1) == 0)continue;
            cnt_node++;

            for(int j =i+1;j<n;j++){
                if(((node >> j)&1) == 0)continue;

                if(dist[i][j] == 1)
                    cnt_edge++;
                max_dist = max(max_dist,dist[i][j]);
            }
        }
        if(cnt_node == cnt_edge + 1)return max_dist;
        return -1;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // vector to store answer;
        vector<int> ans(n-1,0);

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        // distance between two edges = 1;
        for(auto edge : edges){
            dist[edge[0]-1][edge[1]-1] = 1;
            dist[edge[1]-1][edge[0]-1] = 1;
        }

        // floyd warshall algo to find distances
        for(int k =0 ;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]== INT_MAX || dist[j][k] == INT_MAX)continue;
                    dist[i][j] = dist[j][i] = min({dist[i][j],dist[j][i],dist[i][k] + dist[k][j]});
                }
            }
        }

        // iterate over all the subset using bitsmask

        for(int i =1;i<(1<<n);i++){
            int res = solve(i,dist,n);
            cout<<res<<endl;
            if(res >0)ans[res-1]++;

        }

        return ans;
    }
};