#include <iostream>
using namespace std;
int n, k, tmp, c1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> tmp;
        c1 += (tmp == 1);
    }
    cout << c1;
    return 0;
}
// I Love CCF forever.