#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 10;

int T, n, lim, ans;

int max(int a, int b, int c) {
  return max(a, max(b, c));
}
int min(int a, int b, int c) {
  return min(a, min(b, c));
}
int mid(int a, int b, int c) {
  if (max(a, b, c) == a) return max(b, c);
  if (max(a, b, c) == b) return max(a, c);
  if (max(a, b, c) == c) return max(a, b);
}

struct node {
  int a, b, c;
  int del() {
    return max(a, b, c) - mid(a, b, c);
  }
  friend bool operator <(node a, node b) {
    return a.del() > b.del();
  }
};
node a[MAXN];

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    lim = n / 2;
    ans = 0;
    priority_queue<node> x, y, z;
    for (int i = 1; i <= n; i++){
      cin >> a[i].a >> a[i].b >> a[i].c;
      if (max(a[i].a, a[i].b, a[i].c) == a[i].a) {
        x.push(a[i]);
      } else if (max(a[i].a, a[i].b, a[i].c) == a[i].b) {
        y.push(a[i]);
      } else if (max(a[i].a, a[i].b, a[i].c) == a[i].c) {
        z.push(a[i]);
      }
    }
    if (x.size() <= lim && y.size() <= lim && z.size() <= lim) {
      while (!x.empty()) {
        ans += (x.top()).a;
        x.pop();
      }
      while (!y.empty()) {
        ans += (y.top()).b;
        y.pop();
      }
      while (!z.empty()) {
        ans += (z.top()).c;
        z.pop();
      }
    } else {
      if (x.size() > lim) {
        while(x.size() > lim) {
          node tmp = x.top();
          x.pop();
          if (mid(tmp.a, tmp.b, tmp.c) == tmp.b) {
            y.push(tmp);
          } else {
            z.push(tmp);
          }
        }
      } else if (y.size() > lim) {
        while(y.size() > lim) {
          node tmp = y.top();
          y.pop();
          if (mid(tmp.a, tmp.b, tmp.c) == tmp.a) {
            x.push(tmp);
          } else {
            z.push(tmp);
          }
        }
      } else if (z.size() > lim) {
        while(z.size() > lim) {
          node tmp = z.top();
          z.pop();
          if (mid(tmp.a, tmp.b, tmp.c) == tmp.a) {
            x.push(tmp);
          } else {
            y.push(tmp);
          }
        }
      }
      while (!x.empty()) {
        ans += (x.top()).a;
        x.pop();
      }
      while (!y.empty()) {
        ans += (y.top()).b;
        y.pop();
      }
      while (!z.empty()) {
        ans += (z.top()).c;
        z.pop();
      }
    }
    cout << ans << endl;
  }
  return 0;
}
