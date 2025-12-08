#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size() - 1;

        while (st < e) {
            swap(s[st++], s[e--]);
        }
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;

    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    obj.reverseString(s);

    for (char c : s) {
        cout << c << " ";
    }
}