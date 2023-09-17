class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);   //0
        // v.push_back(1);   //1
        // v.push_back(1);   //2
        int last_2s_power=0;
        for(int i=1;i<n+1;i++){
            if(pow(2,last_2s_power+1)==i)
            {
                v.push_back(1);
                last_2s_power+=1;
            }else{
                int rem=i-pow(2,last_2s_power);
                v.push_back(1+v[rem]);
            }
        }
        return v;
    }
};