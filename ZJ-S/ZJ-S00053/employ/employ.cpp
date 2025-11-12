# include <bits/stdc++.h>

# define int long long
# define rint register int

using namespace std;

const int mod = 998244353;
const int N = 510;

string str;
bool flg;
int n, m, c[N];

inline void solve1 () {
  int cnt = 1;
  for (rint i = 2; i <= n; i ++)
  	cnt = (cnt * i) % mod;
  cout << cnt;
  return ;
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("employ.in", "r", stdin);
  freopen ("employ.out", "w", stdout);
  
  cin >> n >> m >> str;
  
  bool flg = true;
  for (rint i = 0; i < n; i ++)
  	if (str[i] == '0') flg = false;

  for (rint i = 1; i <= n; i ++)
  	cin >> c[i]; 
  if (flg == true) solve1 ();

  return 0;
}
