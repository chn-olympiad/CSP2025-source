#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int cnt[20];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i ++)
        if (s[i] >= '0' && s[i] <= '9')
            cnt[s[i] - '0'] ++;
    for (int i = 9; i >= 0; i --)
        for (int j = 1; j <= cnt[i]; j ++)
            cout << i;
    return 0;
}