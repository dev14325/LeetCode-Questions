class Solution {
public:
void decToBinary(int n,int binaryNum[])
{
    // array to store binary number
    
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
   
}
    int minFlips(int a, int b, int c) {
        int binaryA[32]={0};
        int binaryB[32]={0};
        int binaryC[32]={0};
      decToBinary(a,binaryA);
      decToBinary(b,binaryB);
      decToBinary(c,binaryC);
     for(int i=0;i<32;i++){
         cout<<binaryA[i]<<" ";
     }
     cout<<endl;
     for(int i=0;i<32;i++){
         cout<<binaryB[i]<<" ";
     }
     cout<<endl;
     for(int i=0;i<32;i++){
         cout<<binaryC[i]<<" ";
     }
     cout<<endl;
      
      int ans=0;
      for(int i=0;i<32;i++){
          int cnt1=0;
      int cnt2=0;
          int a1=binaryA[i];
          int b1=binaryB[i];
          int c1=binaryC[i];
          if((a1||b1)!=c1){
              cnt1++;
              a1=abs(1-a1);
              if((a1||b1)!=c1){
                  b1=abs(1-b1);
                  cnt1++;
              }
          }
           a1=binaryA[i];
           b1=binaryB[i];
           c1=binaryC[i];
           if((a1||b1)!=c1){
              cnt2++;
              b1=abs(1-b1);
              if((a1||b1)!=c1){
                  a1=abs(1-a1);
                  cnt2++;
              }
          }
          ans+=min(cnt1,cnt2);
      }
      return ans;
    }
};
