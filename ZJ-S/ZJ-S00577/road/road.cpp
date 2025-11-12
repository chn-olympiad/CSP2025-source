#include <bits/stdc++.h>

using namespace std;

#define ll long long


struct edge{
    int a, b, v;
}bas[1000005];

edge nw[10005];

edge nnw[100005];

bool cmp(edge a, edge b) {
    return a.v < b.v;
}

int fa[11005], rnk[11005];

int c[11];
int oth[11][10005];

int find(int x) {
    return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
}

int read() {
    char s = getchar();
    while (!isdigit(s)) {
        s = getchar();
    }
    int sum = 0;
    while (isdigit(s)) {
        sum = (sum << 1) + (sum << 3) + s - '0';
        s = getchar();
    }
    return sum;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        bas[i].a = read();
        bas[i].b = read();
        bas[i].v = read();
    }
    int flag = 1;
    for (int i = 1; i <= k; ++i) {
        c[i] = read();
        if (c[i]) {
            flag = 0;
        }
        for (int j = 1; j <= n; j++) {
            //i - j
            oth[i][j] = read();
        }
    }
    sort(bas + 1, bas + m + 1, cmp);
    int E = 0;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        rnk[i] = 1;
    }
    int t = 0;
    int fx, fy;
    for (int i = 1; i <= m; ++i) {
        fx = find(bas[i].a), fy = find(bas[i].b);
        if (fx ^ fy) {
            if (rnk[fx] < rnk[fy]) {
                fa[fx] = fy;
            }else if (rnk[fx] > rnk[fy]) {
                fa[fy] = fx;
            }else {
                fa[fx] = fy;
                rnk[fy]++;
            }
            nw[++E] = bas[i];
            t++;
            if (t == n - 1)break;
        }
    }
    ll ans = 4e18;
    int i = 0;
    if (flag) {
        i = (1 << k) - 1;
    }
    ll S = 0;
    for (; i < (1 << k); ++i) {
        int E1 = 0;
        ll sum = 0;
        int C = 0;
        for (int j = 1; j <= k; j++) {
            if (!(i & (1 << (j - 1))))continue;
            C++;
            sum += c[j];
            for (int l = 1; l <= n; l++) {
                nnw[++E1] = (edge){j + n, l, oth[j][l]};
            }
        }
        for (int j = 1; j <= n + k; j++) {
            fa[j] = j;
            rnk[j] = 1;
        }
        //cout << i << "!\n";
        sort(nnw + 1, nnw + E1 + 1, cmp);
        S += E1;
        //cout << E1 << endl;
        if (S > 9e6)break;
        int t = 0;
        int e0 = 0, e1=  0;
        for (int j = 1; j <= E + E1; j++) {
            if (e1 == E1 || ((e0 ^ E) && nw[e0 + 1].v < nnw[e1 + 1].v)) {
                
                //cout << nw[e0 + 1].a << ":" << nw[e0 + 1].b << endl;
                fx = find(nw[e0 + 1].a), fy = find(nw[e0 + 1].b);
                if (fx ^ fy) {
                    if (rnk[fx] < rnk[fy]) {
                        fa[fx] = fy;
                    }else if (rnk[fx] > rnk[fy]) {
                        fa[fy] = fx;
                    }else {
                        fa[fx] = fy;
                        rnk[fy]++;
                    }
                    sum += nw[e0 + 1].v;
                    t++;
                }
                e0++;
            }else {
                //cout << nnw[e1 + 1].a << "!" << nnw[e1 + 1].b << endl;
                fx = find(nnw[e1 + 1].a), fy = find(nnw[e1 + 1].b);
                if (fx ^ fy) {
                    if (rnk[fx] < rnk[fy]) {
                        fa[fx] = fy;
                    }else if (rnk[fx] > rnk[fy]) {
                        fa[fy] = fx;
                    }else {
                        fa[fx] = fy;
                        rnk[fy]++;
                    }
                    sum += nnw[e1 + 1].v;
                    t++;
                }
                e1++;
            }
            if (t == n - 1 + C)break;
            if (sum > ans)break;
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}