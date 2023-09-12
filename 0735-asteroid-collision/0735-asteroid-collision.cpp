class Solution {
public:
    void find(vector<int>&result,stack<int>st)
    {
        if(st.empty())
        return;
        int temp=st.top();
        st.pop();
        find(result,st);
        result.push_back(temp);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int>result;
        stack<int>st;
        int i;
        for(i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
            break;
            else{
                result.push_back(asteroids[i]);
            }
        }
        if(asteroids.size()==result.size())
        {
            return result;
        }

        st.push(asteroids[i]);

        for(int j=i+1;j<asteroids.size();j++)
        {
            if(asteroids[j]>0)
            {
                st.push(asteroids[j]);
            }
            // else if(!st.empty()&&abs(asteroids[j])==st.top())
            // {
            //     st.pop();
            // }
            else{
                int flag=0;
                while(!st.empty()&&st.top()<=abs(asteroids[j]))
                {
                    if(st.top()<abs(asteroids[j]))
                    st.pop();
                    else{
                        st.pop();
                        flag=1;
                        break;
                    }
                }
                if(st.empty()&&flag==0)
                {
                    result.push_back(asteroids[j]);
                }
            }
        }

        vector<int>temp;
        find(result,st);
        return result;
    }
};