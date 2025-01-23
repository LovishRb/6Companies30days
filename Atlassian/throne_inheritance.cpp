class ThroneInheritance {
public:
    unordered_map<string,vector<string>> mp;
    unordered_map<string,bool> check_death;
    string king_name;
    ThroneInheritance(string kingName) {
        king_name = kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        check_death[name] = 1;
    }
    
    void solve(vector<string>& res, string parent){
        if(!check_death[parent])res.push_back(parent);

        for(auto child : mp[parent]){
            solve(res,child);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> rs;

        solve(rs,king_name);
        return rs;
    }
};
