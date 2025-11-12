#include <bits/stdc++.h>//Meow
// �����أ���� �д� ���
//???
//wei shen me shi luan ma a QAQ
//QAQ
#define fi first
#define se second
#define A x[1].fi
#define B x[2].fi
#define C x[3].fi
#define X x[1].se
#define Y x[2].se
#define Z x[3].se
using namespace std;
struct node
{
    pair<int, int> x[4];
};
bool cmp(node a, node b)
{
    if (a.A != b.A)
        return a.A > b.A;
    if (a.B != b.B)
        return a.B > b.B;
    if (a.C != b.C)
        return a.C > b.C;
}
bool cmp2(pair<int, int> a, pair<int, int> b) { return a.first >= b.first; } // awa
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in", "r", stdin);// pwp
    freopen("club.out", "w", stdout);// qwq
    int t, n;
    cin >> t;
    while (t--)
    {
        int cnt[4] = {0}, sum = 0;
        cin >> n;
        node a[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i].A >> a[i].B >> a[i].C;
            for (int j = 1; j <= 3; ++j)
                a[i].x[j].se = j;
            sort(a[i].x + 1, a[i].x + 4, cmp2);
        }
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; ++i)
        {
            int id1 = a[i].X, id2 = a[i].Y, id3 = a[i].Z;
            if (cnt[id1] + 1 <= n / 2) sum += a[i].A, cnt[id1]++;
            else if (cnt[id2] + 1 <= n / 2) sum += a[i].B, cnt[id2]++;
            else sum += a[i].C, cnt[id3]++;
        }
        cout << sum << '\n';//T^T
    }
    return 0;//QWQ
}
