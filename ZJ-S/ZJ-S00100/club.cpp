#include <bits/stdc++.h>
using namespace std;
struct member {
    int a, b, c;
};
bool a_cmp(member x, member y)
{
    return x.a > y.a;
}
bool b_cmp(member x, member y)
{
    return x.b > y.b;
}
bool c_cmp(member x, member y)
{
    return x.c > y.c;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, ans = 0, ha = 0, hb = 0, hc = 0, ma = 0, mb = 0, mc = 0;
        cin >> n;

        vector<member> m(n);
        vector<member> ca, cb, cc;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i].a >> m[i].b >> m[i].c;
        }

        int head = 0;
        while (head < m.size())
        {
            if (m[head].a >= m[head].b && m[head].a >= m[head].c && m[head].a >= ma)
            {
                ca.push_back(m[head]);
                head++;
                sort(ca.begin(), ca.end(), a_cmp);
                if (ca.size() == n / 2 + 1)
                {
                    m.push_back(ca[ca.size() - 1]);
                    ca.pop_back();
                }
                ma = ca[ca.size() - 1].a;
            }
            else if (m[head].b >= m[head].a && m[head].b >= m[head].c && m[head].b >= mb)
            {
                cb.push_back(m[head]);
                head++;
                sort(cb.begin(), cb.end(), b_cmp);
                if (cb.size() == n / 2 + 1)
                {
                    m.push_back(cb[cb.size() - 1]);
                    cb.pop_back();
                }
                mb = cb[cb.size() - 1].b;
            }
            else if (m[head].c >= m[head].b && m[head].c >= m[head].a && m[head].c >= mc)
            {
                cc.push_back(m[head]);
                head++;
                sort(cc.begin(), cc.end(), c_cmp);
                if (cc.size() == n / 2 + 1)
                {
                    m.push_back(cc[cc.size() - 1]);
                    cc.pop_back();
                }
                mc = cc[cc.size() - 1].c;
            }

            else if (m[head].a >= ma || ca.size() < n / 2)
            {
                ca.push_back(m[head]);
                head++;
                sort(ca.begin(), ca.end(), a_cmp);
                if (ca.size() == n / 2 + 1)
                {
                    m.push_back(ca[ca.size() - 1]);
                    ca.pop_back();
                }
                ma = ca[ca.size() - 1].a;
            }
            else if (m[head].b >= mb || cb.size() < n / 2)
            {
                cb.push_back(m[head]);
                head++;
                sort(cb.begin(), cb.end(), b_cmp);
                if (cb.size() == n / 2 + 1)
                {
                    m.push_back(cb[cb.size() - 1]);
                    cb.pop_back();
                }
                mb = cb[cb.size() - 1].b;
            }
            else if (m[head].c >= mc || cc.size() < n / 2)
            {
                cc.push_back(m[head]);
                head++;
                sort(cc.begin(), cc.end(), c_cmp);
                if (cc.size() == n / 2 + 1)
                {
                    m.push_back(cc[cc.size() - 1]);
                    cc.pop_back();
                }
                mc = cc[cc.size() - 1].c;
            }
            
        }

        for (member a : ca)
        {
            ans += a.a;
        }
        for (member b : cb)
        {
            ans += b.b;
        }
        for (member c : cc)
        {
            ans += c.c;
        }
        cout << ans << "\n";
    }
    return 0;
}