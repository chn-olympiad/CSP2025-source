#include<bits/stdc++.h>
using namespace std;
namespace IHAVENOEGG {
  #define ll long long
  int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while(T--) {
      int n; cin >> n;
      array<vector<int>,3>a;
      for(int j = 0; j < 3; j++)
        a[j].resize(n);
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
          cin >> a[j][i];
        }
      }
      ll res = 0;
      auto foo = [&](bool g){
        vector<int>c(n);
        iota(c.begin(),c.end(),0);
        sort(c.begin(),c.end(),[&](int x,int y)->bool{
          return 
          a[0][x] - a[1][x] == a[0][y] - a[1][y] ?
          a[2][x] - a[1][x] == a[2][y] - a[1][y] ?
          a[2][x] - a[0][x] >  a[2][y] - a[0][y] :
          a[2][x] - a[1][x] >  a[2][y] - a[1][y] :
          a[0][x] - a[1][x] <  a[0][y] - a[1][y] ;
        });
        ll ans = 0; const int m = n >> 1;
        vector<bool>vis(n, 0);
        deque<pair<int, int>> dq0, dq1, dq2;
        for(int i = 0; i < m; i++)
          ans += a[1][c[i]], dq1.push_back({i, a[2][c[i]] - a[1][c[i]]});
        for(int i = m; i < n; i++)
          ans += a[0][c[i]], dq0.push_back({i, a[2][c[i]] - a[0][c[i]]});
        sort(dq1.begin(), dq1.end(), greater<pair<int, int>>{});
        sort(dq0.begin(), dq0.end(), greater<pair<int, int>>{});
        int c2 = 0, p = m;
        auto getnum = [&]{
          while(vis[c[p]]) ++p;
          return (a[1][c[p]] - a[0][c[p]]);
        };
        auto movep = [&]{
          if(getnum() >= 0) {
            ans += getnum(), ++p;
          }
        };
        while((!dq0.empty() || !dq1.empty() || !dq2.empty()) && c2 < m) {
          res = max(res, ans);
          while(!dq0.empty() && dq0.front().first < p) {
            int x = dq0.front().second, i = dq0.front().first; dq0.pop_front();
            dq2.push_back({i, a[2][c[i]] - a[1][c[i]]});
          }
          if(!dq1.empty() &&
             (dq0.empty() || dq1.front().second + max(getnum(), 0) >= dq0.front().second) &&
             (dq2.empty() || dq1.front().second >= dq2.front().second)) {
            int x = dq1.front().second, i = dq1.front().first; dq1.pop_front();
            ans += x, res = max(res, ans), ++c2, movep(), res = max(res, ans);
          } else if(!dq0.empty() && 
          (dq2.empty() || dq0.front().second >= dq2.front().second + max(getnum(), 0))){
            int x = dq0.front().second, i = dq0.front().first; dq0.pop_front();
            ans += x, res = max(res, ans), ++c2, vis[c[i]] = 1;
          } else if(!dq2.empty()) {
            int x = dq2.front().second, i = dq2.front().first; dq2.pop_front();
            ans += x, res = max(res, ans), ++c2, movep(), res = max(res, ans);
          }
        }
      };
      foo(0); swap(a[1], a[2]);
      foo(0); swap(a[0], a[2]);
      foo(0); swap(a[1], a[2]);
      foo(0); swap(a[0], a[2]);
      foo(0); swap(a[1], a[2]);
      foo(0); swap(a[0], a[2]);
      // foo(1); swap(a[1], a[2]);
      // foo(1); swap(a[0], a[2]);
      // foo(1); swap(a[1], a[2]);
      // foo(1); swap(a[0], a[2]);
      // foo(1); swap(a[1], a[2]);
      // foo(1); swap(a[0], a[2]);
      cout << res << '\n';
    }
    return 0;
  }
};
/*
g++ -o o club.cpp -std=c++14 -Wall -DLOCAL -O2
1
2
1 0 0
1 0 0
*/
#include<bits/stdc++.h>
using namespace std;
namespace YOUHAVENOEGG {
  int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while(T--) {
      int n; cin >> n;
      array<vector<int>,3>a;
      for(int j = 0; j < 3; j++)
        a[j].resize(n);
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
          cin >> a[j][i];
        }
      }
      ll res = 0;
      auto foo = [&](bool g){
        vector<int>c(n), d(n), e(n);
        iota(c.begin(),c.end(),0);
        iota(e.begin(),e.end(),0);
        sort(c.begin(),c.end(),[&](int x,int y)->bool{
          return 
          a[0][x] - a[1][x] == a[0][y] - a[1][y] ?
          a[2][x] - a[1][x] == a[2][y] - a[1][y] ?
          a[2][x] - a[0][x] >  a[2][y] - a[0][y] :
          a[2][x] - a[1][x] >  a[2][y] - a[1][y] :
          a[0][x] - a[1][x] <  a[0][y] - a[1][y] ;
        });
        ll ans = 0; int m = n >> 1;
        for(int i = 0; i < m; i++)
          ans += a[1][c[i]], d[c[i]] = a[2][c[i]] - a[1][c[i]];
        for(int i = m; i < n; i++)
          ans += a[0][c[i]], d[c[i]] = a[2][c[i]] - a[0][c[i]];
        sort(e.begin(),e.end(),[&](int x,int y)->bool{
          return d[c[x]] == d[c[y]] ? x < y : d[c[x]] > d[c[y]];
        });
        vector<bool>vis(n, 0);
        list<pair<int, int>> dq;
        int p = m, c0 = m, c1 = m, c2 = 0;
        auto movep = [&]{
          while(p < n && vis[c[p]]) ++p;
          if(a[1][c[p]] >= a[0][c[p]] || g) {
            ans -= a[0][c[p]], ans += a[1][c[p]];
            --c0, ++c1, ++p;
          }
        };
        res = max(ans, res);
        for(int i = 0; i < n * 2 && c2 < m; i++) {
          if(i < n && (dq.empty() || d[c[e[i]]] >= dq.front().first)) {
            if(e[i] < p) {
              if(e[i] >= m) {
                dq.push_back({a[2][c[e[i]]] - a[1][c[e[i]]], c[e[i]]});
              } else {
                ans += a[2][c[e[i]]] - a[1][c[e[i]]];
                res = max(ans, res);
                ++c2, --c1, movep();
              }
            } else {
              ans += a[2][c[e[i]]] - a[0][c[e[i]]];
              ++c2, --c0, vis[c[e[i]]] = 1;
            }
          } else {
            ans += dq.front().first,
            res = max(ans, res);
            ++c2, --c1, movep();
            dq.pop_front();
          }
          res = max(ans, res);
        }
      };
      foo(0); swap(a[1], a[2]);
      foo(0); swap(a[0], a[2]);
      foo(0); swap(a[1], a[2]);
      foo(0); swap(a[0], a[2]);
      foo(0); swap(a[1], a[2]);
      foo(0); swap(a[0], a[2]);
      // foo(1); swap(a[1], a[2]);
      // foo(1); swap(a[0], a[2]);
      // foo(1); swap(a[1], a[2]);
      // foo(1); swap(a[0], a[2]);
      // foo(1); swap(a[1], a[2]);
      // foo(1); swap(a[0], a[2]);
      cout << res << '\n';
    }
    return 0;
  }
};
#ifndef LOCAL
int main() {
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  YOUHAVENOEGG::main();
}
#else
signed main(signed argc, char*argv[]) {
  if(argc >= 3) {
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
  }
  IHAVENOEGG::main();
}
#endif