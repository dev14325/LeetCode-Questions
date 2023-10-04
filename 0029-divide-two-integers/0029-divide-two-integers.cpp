class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        bool sign=false;
        if(dividend<0 && divisor >0){
            sign=true;
        }
        else if(dividend>0 && divisor<0){
            sign=true;
        }
        long dvd=labs(dividend);
        long dvs=labs(divisor);
        long long temp=0,q=0;
        for(int i=31;i>=0;i--){
            if(temp+(dvs<<i)<=dvd){
                temp+=dvs<<i;
                q+=1LL<<i;
            }
        }
        if(sign){
            return -q;
        }
        return q;
    }
};