#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;

const LL Maxn = 1e5 + 5;

struct Node {
    LL mVal, m2Val, Id1, Id2;
} Vct[Maxn];

struct Node2 {
    LL Diff, Id;
    bool operator < (const Node2& a) const {
        return Diff > a.Diff;
    }
};
priority_queue<Node2> Pque;

LL Cnt[4];

void init() {
    while (!Pque.empty())  Pque.pop();
    return;
}

LL getM2(LL a, LL b, LL c, LL mVal) {
    if (mVal == a)  return max(b, c);
    else if (mVal == b)  return max(a, c);
    else  return max(a, b);
}

LL getId(LL Num, LL a, LL b, LL c) {
    if (Num == a)  return 1;
    else if (Num == b)  return 2;
    else  return 3;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    LL t, n, a, b, c, Res = 0;
    Node2 Cur = {0, 0};
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        for (LL i = 1; i <= n; ++i) {
            cin >> a >> b >> c;
            Vct[i].mVal = max(max(a, b), c);
            Vct[i].Id1 = getId(Vct[i].mVal, a, b, c);
            Vct[i].m2Val = getM2(a, b, c, Vct[i].mVal);
            if (Vct[i].mVal == a)  Vct[i].Id2 = (Vct[i].m2Val == b ? 2 : 3);
            else if (Vct[i].mVal == b)  Vct[i].Id2 = (Vct[i].m2Val == a ? 1 : 3);
            else  Vct[i].Id2 = (Vct[i].m2Val == a ? 1 : 2);
        }

        sort(Vct + 1, Vct + n + 1, [](const Node& x, const Node& y) {return x.mVal > y.mVal;});


        Cnt[0] = Cnt[1] = Cnt[2] = Cnt[3] = Res = 0;
        for (LL i = 1; i <= n; ++i) {
            ++Cnt[Vct[i].Id1];
            Pque.push({Vct[i].mVal - Vct[i].m2Val, i});
            Res += Vct[i].mVal;
        }

        while (!Pque.empty()) {
            if (Cnt[0] <= n / 2 && Cnt[1] <= n / 2 && Cnt[2] <= n / 2 && Cnt[3] <= n / 2)  break;
            Cur = Pque.top();
            if (Cnt[Vct[Cur.Id].Id1] <= n / 2)  continue;
            Pque.pop();
            Res = Res - Vct[Cur.Id].mVal + Vct[Cur.Id].m2Val;
            --Cnt[Vct[Cur.Id].Id1];
            ++Cnt[Vct[Cur.Id].Id2];
        }

        cout << Res << '\n';
    }

    return 0;
}
