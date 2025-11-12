#include <bits/stdc++.h>
using namespace std;

char s[1000001];
int a[1000001];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf ("%s", s + 1);
    int l = strlen(s + 1);
    int n = 0;
    for (int i = 1; i <= l; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            n++;
            a[n] = s[i] - '0';
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        printf ("%d", a[i]);
    }
    return 0;
}
