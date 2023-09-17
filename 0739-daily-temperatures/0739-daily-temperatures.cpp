class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>v;
        int n=temp.size();
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty())
            v.push_back(0);
            else if(!s.empty()&& s.top().first > temp[i])
            v.push_back(s.top().second - i);
            else if(!s.empty()&& s.top().first <=temp[i]) {
                while(!s.empty()&& s.top().first <=temp[i]){
                    s.pop();
                }
                if(s.empty())
                v.push_back(0);
                else
                v.push_back(s.top().second - i);
            }
            s.push({temp[i] ,i});

        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};