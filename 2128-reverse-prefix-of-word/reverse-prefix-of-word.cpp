class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIndex = word.find(ch); // Find ch
        reverse(word.begin(), word.begin() + chIndex + 1 ); // Reverse prefix
        return word;
    }
};