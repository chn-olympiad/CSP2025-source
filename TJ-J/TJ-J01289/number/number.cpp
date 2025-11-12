#include<bits/stdc++.h>
using namespace std;

char s[1000005];

int t[15];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int i = 1; i <= l; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            t[s[i] - '0']++;
    }
    for (int i = 9; i >= 0;) {
        if (t[i]) {
            printf("%d", i);
            t[i]--;
        } else
            i--;
    }
    return 0;
}
