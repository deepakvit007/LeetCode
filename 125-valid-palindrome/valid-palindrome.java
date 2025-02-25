class Solution {

    boolean help(int start, int end, String s) {
        if (start >= end) return true;

        if (s.charAt(start) != (s.charAt(end))) return false;

        return help(start + 1, end - 1, s);
    }

    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
       StringBuilder modified = new StringBuilder();
        for(char c : s.toCharArray())
        {
            if(Character.isLetterOrDigit(c))
            {
               modified.append(c);
            }
        }
        int start = 0;
        int end = modified.length() - 1;

        return help(start, end, modified.toString());
    }
}
