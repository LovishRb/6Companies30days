class Solution {
public:
    void dijkstra(int n, vector<vector<pair<int, int>>>& adjacencyList, vector<int>& shortest_path_distance, int src) {
        
        shortest_path_distance.resize(n, INT_MAX);
        shortest_path_distance[src] = 0;

        
        priority_queue<pair<int, int> > pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [curr_dist, curr_city] = pq.top();
            pq.pop();


            for (auto [city, weight] : adjacencyList[curr_city]) {
                if (shortest_path_distance[city] > curr_dist + weight) {
                    shortest_path_distance[city] = curr_dist + weight;
                    pq.push({shortest_path_distance[city], city});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int, int>>> adj(n);

        
        for (const auto& edge : edges) {
            int left = edge[0];
            int right = edge[1];
            int weight = edge[2];

            adj[left].emplace_back(right, weight);
            adj[right].emplace_back(left, weight);
        }

        
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        
        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, result[i], i);
        }

        // to find the min reachable cities;
        int ans = -1;
        int count_Of_min_reachable_cities = n;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (result[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= count_Of_min_reachable_cities) {
                count_Of_min_reachable_cities = count;
                ans = i;
            }
        }
        return ans;
    }
};
