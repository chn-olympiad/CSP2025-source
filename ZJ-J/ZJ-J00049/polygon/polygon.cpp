# include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const long long N = 5010;

long long n, ans;
long long a[N];
bool b[N];

bool flg = true;

inline void solve () {
  while (b[0] == 0) {
  	long long j = n;
  	while (b[j]) j --;
  	b[j] = 1;
  	for (int i = j + 1; i <= n; i ++) b[i] = 0;
  	long long mx = 0, cnt = 0, x = 0;
  	for (int i = 1; i <= n; i ++)
  	  if (b[i] == 1)
		cnt = cnt + a[i],
  	    mx = max (mx, a[i]),
  	    x ++;
	if (x <= 2) continue;
	if (cnt > mx * 2) ans = (ans + 1) % mod;
  }
  return ;
}

inline long long C_ (long long x, long long y) {
  long long res = 1;
  long long cnt = (x - y);
  for (int i = y + 1; i <= x; i ++) {
  	res = res * i;
  	if (res >= cnt && res % cnt == 0 && cnt > 1) {
  	  res = res / cnt;
  	  cnt --;
	}
	res = res % mod;
  }
  while (cnt > 1)
  	res = res / cnt,
  	cnt --;
  
  return res;
}

inline void slove () {
  if (n <= 2) {
  	ans = 0;
  	return ;
  }
  
  for (int i = 3; i <= n; i ++)
    ans = (ans + C_ (n, i)) % mod;
  return ;
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("polygon.in", "r", stdin);
  freopen ("polygon.out", "w", stdout);
  
  cin >> n;
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
    if (a[i] != 1) flg = false;
  }
  if (flg == true) slove ();
  else solve ();
  cout << ans;
  return 0;
}

