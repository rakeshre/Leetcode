class TimeMap {
public:
    unordered_map<string, map<int, string>> kvstore;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        kvstore[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(kvstore.find(key)==kvstore.end()){
            return "";
        } //this line prevents tle.
        // auto x=kvstore[key];
        // auto itr=x.upper_bound(timestamp);
        auto itr=kvstore[key].upper_bound(timestamp);//writing it as one line to prevent tle. 
        if(itr==kvstore[key].begin()){
            return "";
        }
            return prev(itr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */