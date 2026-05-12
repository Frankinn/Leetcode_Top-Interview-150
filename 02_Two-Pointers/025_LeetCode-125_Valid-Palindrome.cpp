/*
 * Top Interview 150 - 025 / 150
 * Problem: 125. Valid Palindrome
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Two Pointers
 */
class Solution {
private:
/*  //practice
    bool isAlphaNum(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool equal(char a, char b){
        if((a >= '0' && a <= '9') || (b >= '0' && b <= '9'))
            return a == b;
        else
            return (a == b) || ((a+32) == b) || ((a-32) == b);
    }
*/
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size()-1; i < j; ++i, --j){
            while(i < j && !isalnum(s[i]))
                ++i;
            while(i < j && !isalnum(s[j]))
                --j;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};