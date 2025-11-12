#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    int n = rand() % 300 * 2 + 2;
    cout << "1\n" << n << "\n";
    for (int i = 1;i <= n;i ++) {
        int x = rand() % 100000 + 1;
        int y = rand() % 100000 + 1;
        int z = rand() % 100000 + 1;
        cout << x << " " << y << " " << z << "\n";
    }
}