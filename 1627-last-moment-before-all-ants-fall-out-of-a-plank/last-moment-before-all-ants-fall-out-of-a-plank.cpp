class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // The one that is farthest from the left end, but desires to go in the left
        // direction, will be the last one to go off of the plank from the left side.
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        
        // Similarly,
        // The one that is farthest from the right end, but desires to go in the right
        // direction, will be the last one to go off of the plank from the right side.
        int minRight = right.empty() ? n : *min_element(right.begin(), right.end());
        
        // The one among above two would be the last one to off of the plank among all.
        return max(maxLeft, n - minRight);
    }
};