class Solution {
public:

    // comparator to sort it width wise and is same width, sort it in decreasing order of height
    static bool comparator(vector<int>& v1 , vector<int>& v2){
        if(v1[0] == v2[0]) 
            return v1[1] > v2[1];

        return v1[0] < v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comparator);

        vector<int> longest_increasing_subsequence;

        for(int i =0;i<envelopes.size();i++){
            int curr_element = envelopes[i][1];
            // - longest_increasing_subsequence.begin() to handle 0-based indexing
            int index_curr_element_to_be_inserted = lower_bound(longest_increasing_subsequence.begin(),longest_increasing_subsequence.end(),curr_element) - longest_increasing_subsequence.begin();

            if(index_curr_element_to_be_inserted >= longest_increasing_subsequence.size())
                longest_increasing_subsequence.push_back(curr_element);
            
            else
                longest_increasing_subsequence[index_curr_element_to_be_inserted] = curr_element;

        }
        return longest_increasing_subsequence.size();
    }
};
