class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,pair<int,int>>> pq;
        bool alice_turn=true;
        // bool bob_turn=false;

        for(int i =0;i<aliceValues.size();++i){
            pq.push({aliceValues[i] + bobValues[i] , {aliceValues[i],bobValues[i]}});
        }
        int ans=0;
        while(!pq.empty()){
            auto it = pq.top();
            auto sum = it.first;
            pair<int,int> pair_alice_bob = it.second;
            if(alice_turn){
                ans += pair_alice_bob.first;
                alice_turn=false;
                // bob_turn = true;
            }
            else{
                ans-=pair_alice_bob.second;
                alice_turn=true;
                // bob_turn = false;
            }


            pq.pop();
            cout<<sum << " " << pair_alice_bob.first <<" "<<pair_alice_bob.second<<endl;
        
        }

        if(ans==0)return 0;
        if(ans<0)return -1;
        else return 1;
    }
};