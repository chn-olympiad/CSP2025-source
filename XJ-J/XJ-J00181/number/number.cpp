#include <iostream>
#include <cstring>
#include <algorithm>
//haihaihai_Long_Live_the_People's_Republic_of_China!!!
using std::cin;
using std::cout;
const int N = 1e6 + 5;
char s[N];
int ans[10], cnt;
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> (s + 1);
    for (int i = 1; i <= strlen(s + 1); i++)
        if (s[i] >= '0' && s[i] <= '9')
            ans[s[i] - '0']++;
    for (int i = 9; i >= 0; i--)
        for (int j = 1; j <= ans[i]; j++)
            cout << i;
}