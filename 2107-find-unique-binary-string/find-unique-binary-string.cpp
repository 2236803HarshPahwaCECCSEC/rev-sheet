#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> number(nums.begin(), nums.end());

        // Generate all possible binary strings of length n
        for (int i = 0; i < (1 << n); i++) {
            string candidate = "";
            for (int j = n - 1; j >= 0; j--) {
                candidate += (i & (1 << j)) ? '1' : '0';
            }
            if (number.count(candidate) == 0) {
                return candidate;
            }
        }
        return ""; // This line should theoretically never be reached
    }
};
