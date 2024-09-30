class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookie) {
        // Sort greed factors and cookie sizes
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());

        int i = 0; // Pointer for greed array (children)
        int j = 0; // Pointer for cookie array (cookies)
        int count = 0; // To track the number of content children

        // Iterate through both arrays
        while (i < greed.size() && j < cookie.size()) {
            // If the current cookie can satisfy the current child's greed
            if (cookie[j] >= greed[i]) {
                count++;  // Increment count for a content child
                i++;      // Move to the next child
            }
            // Move to the next cookie (whether it satisfied a child or not)
            j++;
        }

        return count; // Return the number of content children
    }
};
