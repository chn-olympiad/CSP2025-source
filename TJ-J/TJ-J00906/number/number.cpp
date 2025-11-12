#include<bits/stdc++.h>
using namespace std;

#define ll long long

char a[1000005];
int cnt[10];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", a + 1);
    int n = strlen(a + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] >= '0' && a[i] <= '9')cnt[a[i] - '0']++;
    }
    for(int i = 9; i >= 0; i--) {
        for(int j = 1; j <= cnt[i]; j++)printf("%d", i);
    }
    return 0;
}

