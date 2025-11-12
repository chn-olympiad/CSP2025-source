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

const i64 mod = 998244353;

const int MaxN = 507;

int n, m, ca[MaxN], lu[MaxN];
i64 ans;

// namespace solve {
//   vector<int> cnt_lr[MaxN], cnt_gr[MaxN];
//   void main(int *a) {
//     int cnt = 0;
//     For (i, 0, n+1) {
//       cnt_lr[i] = 0;
//       cnt_gr[i] = 0;
//     }
//     For (i, 0, n) {
//       cnt += !a[i];
//       if (lu[i]) {
//         if (a[i]) ++cnt_gr[cnt+1];
//         else ++cnt_lr[cnt];
//       }
//     }
//   }
// }

// namespace bf {
//   int real[MaxN];
//   void DFS(int i) {
//     if (i == n) {
//       return solve::main(real);
//     }
//     if (!lu[i]) DFS(i+1);
//     else {
//       real[i] = 0;
//       DFS(i+1);
//       real[i] = 1;
//       DFS(i+1);
//     }
//   }
//   void main() {
//     DFS(0);
//   }
// }

namespace bfbf {
  int vis[MaxN];
  int a[MaxN];
  int check() {
    int cnt = 0;
    For (i, 0, n) {
      if (!lu[i] || cnt >= ca[a[i]])
        ++cnt;
    }
    return cnt <= n-m;
  }
  void DFS(int i) {
    if (i == n) {
      ans += check();
      return;
    }
    For (x, 0, n) if (!vis[x]) {
      a[i] = x;
      vis[x] = 1;
      DFS(i+1);
      vis[x] = 0;
    }
  }
  void main() {
    DFS(0);
  }
}

namespace mask {
  const int MaxS = (1<<18);
  i64 dp[MaxS][19];
  void main() {
    dp[0][0] = 1;
    For (s, 0, 1<<n) {
      int cnt = __builtin_popcount(s);
      For (i, 0, cnt+1) {
        For (j, 0, n) if (!(s&(1<<j))) {
          int t = s|(1<<j);
          if (!lu[cnt]) (dp[t][i+1] += dp[s][i]) %= mod;
          else {
            if (ca[j] <= i) (dp[t][i+1] += dp[s][i]) %= mod;
            else (dp[t][i] += dp[s][i]) %= mod;
          }
        }
      }
    }
    For (i, m, n+1) (ans += dp[(1<<n)-1][n-i]) %= mod;
  }
}

namespace sub1 {
  void main() {
    i64 orig = 1;
    For (i, 1, n+1) (orig *= i) %= mod;
    vector<int> cnt(n+1);
    For (i, 0, n) ++cnt[ca[i]];
    For (i, 1, n+1) cnt[i] += cnt[i-1];
    int c = 0;
    i64 ret = 1;
    For (i, 0, n) {
      if (lu[i]) {
        (ret *= cnt[i]-c) %= mod;
        ++c;
      }
    }
    int cnt0 = n-accumulate(lu,lu+n,0);
    For (i, 1, cnt0+1) (ret *= i) %= mod;
    ans = (orig+mod-ret)%mod;
  }
}

namespace sub2 {
  void main() {
    if (*min_element(lu,lu+n) == 0) return;
    if (*min_element(ca,ca+n) == 0) return;
    ans = 1;
    For (i, 1, n+1) (ans *= i) %= mod;
  }
}

namespace work {
  void main() {
    scanf("%d%d", &n, &m);
    For (i, 0, n) {
      char c;
      do c = getchar(); while (!isdigit(c));
      lu[i] = c-'0';
    }
    For (i, 0, n) scanf("%d", ca+i);
    // int sum_s = accumulate(lu, lu+n, 0);
    // if (sum_s <= 18) bf::main();
    // else if (m == 1) sub1::main();
    // else if (m == n) sub2::main();
    if (n <= 10) bfbf::main();
    else if (n <= 18) mask::main();
    else if (m == 1) sub1::main();
    else if (m == n) sub2::main();
    // mask::main();
    printf("%lld\n", ans);
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  work::main();
  fclose(stdin);
  fclose(stdout);
  return 0;
}