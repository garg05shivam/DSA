#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BS(int n) {
        int s = 0;
        int e = n;
        long long mid = s + (e - s) / 2;
        long long ans = -1;

        while (s <= e) {
            long long square = mid * mid;

            if (square == n) {
                return mid;
            }

            if (square < n) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }

    int mySqrt(int x) {
        return BS(x);
    }
};

int main() {
    Solution obj;
    int x;
    cin >> x;

    cout << obj.mySqrt(x);

    return 0;
}
