bool helper(vector<int> &a,vector<int> &b ){
    return a[1]<b[1];
}
class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        int i=0, arrow=0,n=points.size(),e;
        sort(points.begin(),points.end(),helper);
        while(i<n){
            e=points[i][1];
            arrow++;
            i++;
            while(i<n && points[i][0]<=e)i++;
        }
        return arrow;
    }
};