#include <iostream>
#include <vector>
using namespace std;

int N, K;
int s[500008];
int f[500008];
int t[500008];
int v[500008];
int pos=500008;
int ans;

void d(int i,int cnt) {
    //cout << i << " " << cnt << endl;
    if (cnt>ans) {
        ans = cnt;
    }else if (pos<i) {
        return;
    }
    if (i>N) {
        return;
    }
    if (f[i]) {
        int j=f[i]+1;
        for (; j <= N; j++) {
            if (f[j])
                break;
        }
        d(j, cnt + v[i]);
    }

    int j=i+1;
    for (; j <= N; j++) {
        if (f[j])
            break;
    }
    d(j, cnt);
    return;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> N >> K;
    for (int i = 1;i<=N;i++) {
        cin >> s[i];
        s[i] = s[i - 1] ^ s[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i;j <= N;j++) {
            if ((s[j] ^ s[i - 1]) == K) {
                if (t[j]) {
                    f[t[j]] = 0;
                    v[t[j]] = 0;
                }
                f[i] = j;
                t[j] = i;
                v[i] = 1;
                break;
            }
        }
    }
    int ma = 0;

    for (int i = 1; i <= N;i++) {
        if (f[i] && ma && ma<f[i]) {
            int a=t[ma],b=ma,c=i,d=f[i];
            ma = max(ma, f[i]);
            v[c] = 0;
            v[a]++;
            t[b] = 0;
            t[d] = a;
            f[c] = 0;
            f[a] = d;
        }
        ma = max(ma, f[i]);
    }

    d(1, 0);
    cout << ans;

    return 0;
}

/*
4 2
2 1 0 3

2

4 3
2 1 0 3

2

4 0
2 1 0 3

1
*/