class DataStream {
public:
    int v,c;
    int count=0;
    DataStream(int value, int k) {
        v= value;
        c=k;
    }
    
    bool consec(int num) {
        if (num == v) {
            count++; 
        } else {
            count = 0; 
        }
        return count >= c;

    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */