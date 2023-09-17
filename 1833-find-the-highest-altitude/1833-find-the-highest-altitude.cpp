class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int h_alt = 0;
        for (int i = 0; i < gain.size(); i++){
            sum += gain[i];
            h_alt = max(h_alt, sum);
        }

        return h_alt;
    }
};