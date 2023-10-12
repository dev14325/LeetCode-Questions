/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr){
        int l = 1, r = mountainArr.length()-2, n = mountainArr.length();
        while (l != r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1; 
            } else {
                r = mid;
            }
        }
        return l;
    }
    int findLeft(int target, MountainArray &mountainArr,int l,int r){
        while(l<=r){
            int mid = (r - l)/2 + l;
            if(mountainArr.get(mid) == target) return mid;
            if(mountainArr.get(mid) > target){
                r = mid -1;
            }
            else l = mid + 1;
        }
        return -1;
    }
    int findRight(int target, MountainArray &mountainArr,int l,int r){
        while(l<=r){
            int mid = (r - l)/2 + l;
            if(mountainArr.get(mid) == target) return mid;
            if(mountainArr.get(mid) <= target){
                r = mid -1;
            }
            else l = mid + 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr);
        // return peak;
        int left = findLeft(target, mountainArr,0,peak);
        if(left != -1) return left;
        int right = findRight(target, mountainArr,peak,n-1);
        if(right != -1) return right;
        return -1;
    }
};