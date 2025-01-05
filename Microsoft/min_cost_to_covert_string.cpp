class Solution {
public:

    vector<long long> dijkstra(int start_index , vector<vector<pair<int,int>>>& adjacencyList)
    {
        // to store the min cost to convert of a particular char to all other chars;
        vector<long long > ans(26,-1);

        // store the cost and characters and in increasing order of cost 
        priority_queue < pair<long long,int> ,vector<pair<long long, int>>,  greater<pair<long long , int>> > pq;

        // adding start_character with 0 cost;
        pq.push({0,start_index});

        while(!pq.empty()){
            auto [curr_cost , curr_char] = pq.top();
            pq.pop();

            // if ans is already the minimum possible for a char
            if(ans[curr_char] != -1 && ans[curr_char] < curr_cost) continue;

            for(auto [target_char, cost] : adjacencyList[curr_char]){
                long long total_cost = curr_cost + cost ;
                
                // if total_cost is small, update it;
                if(ans[target_char] == -1 || total_cost < ans[target_char]){
                    ans[target_char] = total_cost;

                    // add it to pq;
                    pq.push({total_cost , target_char});
                }



            }

        }
        return ans;

    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adjacencyList(26);
        // creating a list to store the destinations and costs of a particular source character..
        for(int i =0;i<original.size();i++){
            adjacencyList[original[i] - 'a'].push_back({changed[i] - 'a' , cost[i]});
        }

        // list to store shortest paths for all the characters from a particular character
       vector<vector<long long>> min_cost_of_conversions(26, vector<long long>(26));

        for(int i =0;i<26;i++){
            min_cost_of_conversions[i] = dijkstra(i,adjacencyList);
        }

        long long result_cost = 0;

        for(int i = 0 ; i < source.length() ; i++){
            if(source[i] != target[i]){
                long long cost_of_converting = min_cost_of_conversions[source[i] - 'a'][target[i]-'a'];

                if(cost_of_converting == -1)
                    return -1;
                result_cost += cost_of_converting;
            }

        }

        return result_cost;
    }
};