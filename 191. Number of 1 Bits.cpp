#include <iostream>
using namespace std;

int hammingWeight(int n) {
    int count = 0;
    while (n != 0) {
        if (n & 1) {    // check last bit
            count++;
        }
        n = n >> 1;     // right shift
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = hammingWeight(n);
    cout << "Number of 1 bits (Hamming Weight) = " << result << endl;

    return 0;
}
