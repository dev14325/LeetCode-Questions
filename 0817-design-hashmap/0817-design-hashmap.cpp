class MyHashMap {
public:
    MyHashMap() {
        
    }
    vector<vector<int>> data;
    void put(int key, int value) {
        for(int i = 0; i < data.size(); i++){
         if(data[i][0] == key){
             data[i][1] = value;
             return;
         }
        }
        vector<int> item{key,value};
        data.push_back(item);
        
    }
    
    int get(int key) {
        for(int i = 0; i < data.size(); i++){
         if(data[i][0] == key)return data[i][1];
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i < data.size(); i++){
         if(data[i][0] == key){
             data.erase(data.begin() + i);
             return;
         }
        }
    }
};