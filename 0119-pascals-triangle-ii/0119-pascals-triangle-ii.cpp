class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vt;
        for (int i = 0; i <= rowIndex; i++) {
            vt.push_back(getElement(rowIndex, i));
        }
        return vt;
    }

private:
    map<pair<int, int>, int> memo;

    int getElement(int x, int i) {
        if (i == 0 || i == x) {
            return 1;
        }

        if (memo.find({x, i}) != memo.end()) {
            return memo[{x, i}];
        }

        int result = getElement(x - 1, i - 1) + getElement(x - 1, i);
        memo[{x, i}] = result;
        return result;
    }
};