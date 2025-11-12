#include<bits/stdc++.h>
using namespace std;
int n, m, x, y = 1;
int d = 1;
vector<pair<int, int> > g;
bool cmp(pair<int, int> a, pair<int, int> b) {return a.first > b.first;}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int a;
    for(int i=1; i<=n*m; ++i)
    {
        cin >> a;
        g.push_back(make_pair(a, i));
    }
    sort(g.begin(), g.end(), cmp);
    for(int i=0; i<m; ++i)
    {
        ++x;
        for(int j=0; j<n; ++j)
        {
            if(j > 0)
                y += d;
            if(g[i*n+j].second == 1)
            {
                cout << x << ' ' << y;
                return 0;
            }
        }
        d *= -1;
    }
    return 0;
}
