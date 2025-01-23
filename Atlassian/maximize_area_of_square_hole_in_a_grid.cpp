class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int max_h = 1;
        int count=1;
        for(int i =0;i<hBars.size()-1;i++){
            if(hBars[i] == hBars[i+1] - 1)count++;
            else count = 1;
            // cout<<count<<endl;
            max_h = max(max_h,count);
        }

        count=1;
        int max_v = 1;
        for(int i =0;i<vBars.size()-1;i++){
            if(vBars[i] == vBars[i+1] - 1)count++;
            else count = 1;

            // cout<<count<<endl;
            max_v = max(max_v,count);
        }


        int mini = min(max_v,max_h);
        // cout<<mini<<endl;

        return (mini + 1) *(mini + 1);
    }
};