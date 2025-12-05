#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // Special case for 0
        if (num == 0) return 1;

        // Calculate the bitmask
        unsigned mask = ~0; // All bits set to 1
        while (num & mask) mask <<= 1;
        mask = ~mask;

        // XOR num with mask to flip its bits
        return num ^ mask;
    }
};

int main() {
    Solution obj;
    int num;
    cin >> num;
    cout << obj.findComplement(num);
    return 0;
}
