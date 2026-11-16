class TimeMap {
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if( mp.find(key) != mp.end()) {
            mp[key].push_back({timestamp, value});
        }
        else {
            mp.insert({key, {{timestamp, value}}});
        }
        
    }
    
    string get(string key, int timestamp) {
        auto mpIt = mp.find(key);
        if( mpIt == mp.end()) {
            return "";
        }
        auto& vec = mpIt->second;
        auto comp = [](int val, const std::pair<int, std::string>& p) {
                        return val < p.first;
                    };
        auto it = upper_bound(vec.begin(), vec.end(), timestamp, comp);
        if(it != vec.begin()){
            return prev(it)->second;
        }
        return "";
    }
};
