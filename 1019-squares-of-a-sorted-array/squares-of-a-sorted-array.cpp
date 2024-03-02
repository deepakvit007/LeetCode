class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int i = 0, j = a.size() - 1, k = j;
        vector <int> ret(k + 1, 0);
        while (k >= 0) {
            if (abs(a[i]) > abs(a[j])) ret[k--] = a[i] * a[i++];
            else ret[k--] = a[j] * a[j--];
        }
        return ret;
    }
};