// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//     freopen("xor.out", "w", stdout);
//     freopen("xor.in", "r")
//     srand(time(0));
//     cout << 1 << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool getxor(vector <int> a, int n, int b) {
    int sum = 0;
    sum = sum + a[n] ^ a[n + 1];
    for (int i = n; i <= b; i++) {
        sum ^= a[i];
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, idn;
    cin >> n >> idn;
    int sum = 0;
    vector <int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int k = 0; k < n; k++) {
    //             for (int m = 0; m < n; m++)  {
    //                 if (getxor(a, i, j) == getxor(a, k, m) && getxor(a, k, m) == idn) {
    //                     if (i <= j && j <= k && k <= m) {
    //                         ans++;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    ans = sum - k;
    cout << ans << '\n';
    return 0;
}