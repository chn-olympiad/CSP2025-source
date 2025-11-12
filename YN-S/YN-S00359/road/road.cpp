#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;

const LL Maxn = 1e4 + 5;
const LL Maxm = 1e6 + 5;
const LL Maxk = 10 + 5;
const LL Inf = 1e18;

struct Node {
    LL u, v, w;
} Edge[Maxm];

LL Vct_c[Maxk], Edj[Maxk][Maxn];
bool Visj[Maxk], Visij[Maxk][Maxn];

LL Father[Maxn];

void Init(LL n) {
    for (LL i = 0; i <= n; ++i)  Father[i] = i;
    return;
}

LL f_find(LL x) {
    if (x == Father[x])  return x;
    else  return Father[x] = f_find(Father[x]);
}

bool f_join(LL x, LL y) {
    x = f_find(x);
    y = f_find(y);
    if (x == y)  return false;
    Father[x] = y;
    return true;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    LL n, m, k, a, b, c;
    cin >> n >> m >> k;
    for (LL i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        Edge[i] = {a, b, c};
    }
    for (LL i = 1; i <= k; ++i) {
        cin >> Vct_c[i];
        for (LL j = 1; j <= n; ++j)  cin >> Edj[i][j];
    }

    sort(Edge + 1, Edge + m + 1, [](const Node& x, const Node& y) {return x.w < y.w;});

    Init(n);

    LL Res = 0, mVal = Inf, Id = 0, Sum = 0;
    for (LL i = 1; i <= m; ++i) {
        if (f_join(Edge[i].u, Edge[i].v) != false) {
            mVal = Edge[i].w, Id = 0;
            for (LL j = 1; j <= k; ++j) {
                Sum = 0;
                if (Visij[j][Edge[i].u] == false)  Sum += Edj[j][Edge[i].u];
                if (Visij[j][Edge[i].v] == false)  Sum += Edj[j][Edge[i].v];
                if (Visj[j] == false)  Sum += Vct_c[j];
                if (Sum < mVal) {
                    mVal = Sum;
                    Id = j;
                }
            }
            if (mVal < Edge[i].w) {
                Visij[Id][Edge[i].u] = true;
                Visij[Id][Edge[i].v] = true;
                Visj[Id] = true;
            }
            Res += mVal;
        }
    }

    cout << Res << '\n';

    return 0;
}
