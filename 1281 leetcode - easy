#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
    int pro = 1;
    int sum = 0;

    while (n != 0) {
        int rem = n % 10;
        pro = pro * rem;
        sum = sum + rem;
        n = n / 10;
    }

    int ans = pro - sum;
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Result = " << subtractProductAndSum(n) << endl;

    return 0;
}
