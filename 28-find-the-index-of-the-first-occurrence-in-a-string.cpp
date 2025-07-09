//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t needle_len = needle.size();
        for (size_t i = 0; i < haystack.size(); i++) {
            if (haystack.compare(i, needle_len, needle) == 0)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int result = sol.strStr(haystack, needle);
    // Expected output: 2
    return result;
}