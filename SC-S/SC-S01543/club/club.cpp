#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define forv(v,adj,fs) for(int v:adj)if(v!=fs)
#define forvw(v,w,adj,fs) for(auto[v,w]:adj)if(v!=fs)
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;
const int _inf32 = 0x3f3f3f3f;
const i64 _inf64 = 0x3f3f3f3f3f3f3f3f;
#define ckmax(a,b) (a=max(a,b))
#define ckmin(a,b) (a=min(a,b))
#define pb emplace_back
#define FI first
#define SE second

const int MaxN = int(1e5+7);

int T;
int n; i64 a[MaxN][3];

namespace work {
  void main() {
    scanf("%d", &T);
    For (cas, 0, T) {
      scanf("%d", &n);
      vector<vector<int>> bak(3);
      vector<i64> oth(n);
      For (i, 0, n) For (j, 0, 3) scanf("%lld", &a[i][j]);
      i64 orig = 0;
      For (i, 0, n) {
        int prf = max_element(a[i], a[i]+3) - a[i];
        i64 mx = a[i][prf];
        i64 sec = -_inf64;
        For (j, 0, 3) if (j != prf) ckmax(sec, a[i][j]);
        bak[prf].pb(i);
        oth[i] = sec-mx;
        orig += mx;
        // if (cas == 1) {
        //   cerr << mx << ' ' << sec << ' ' << oth[i] << endl;
        // }
      }
      i64 ans = orig;
      For (i, 0, 3) {
        if (bak[i].size() > n/2) {
          int need = bak[i].size() - n/2;
          sort(bak[i].begin(), bak[i].end(), [&](int a, int b) {
            return oth[a] > oth[b];
          });
          For (j, 0, need) ans += oth[bak[i][j]];
        }
      }
      printf("%lld\n", ans);
    }
  }
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  work::main();
  fclose(stdin);
  fclose(stdout);
  return 0;
}