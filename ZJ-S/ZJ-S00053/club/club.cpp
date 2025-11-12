# include <bits/stdc++.h>

# define int long long
# define rint register int

using namespace std;

const int N = 1e5 + 10;

struct node {
  int a;
  int b;
  int c;
};

int T, n, lim, cnta, cntb, cntc, sum;
node x[N];
int dita[N], ditb[N], ditc[N];

inline void solve () {
  cin >> n;
  lim = n / 2;
  sum = 0;
  cnta = 0,
  cntb = 0;
  cntc = 0;
  for (rint i = 1; i <= n; i ++) {
  	cin >> x[i].a >> x[i].b >> x[i].c;
	int now1 = abs (x[i].a - x[i].b);
	int now2 = abs (x[i].b - x[i].c);
	int now3 = abs (x[i].c - x[i].a);  	
  	if (x[i].a >= x[i]. b && x[i].a >= x[i].c)
	  dita[++ cnta] = min (now1, now3),
	  sum = sum + x[i].a;
	else if (x[i].b >= x[i].a && x[i].b >= x[i].c)
	  ditb[++ cntb] = min (now1, now2),
	  sum = sum + x[i].b;
	else
	  ditc[++ cntc] = min (now2, now3),
	  sum = sum + x[i].c;
  }

  if (cnta <= lim && cntb <= lim && cntc <= lim) {
  	cout << sum << '\n';
  	return ;
  }
  
  sort (dita + 1, dita + cnta + 1);
  sort (ditb + 1, ditb + cntb + 1);
  sort (ditc + 1, ditc + cntc + 1);

  if (cnta > lim) {
  	for (rint i = 1; i <= cnta - lim; i ++)
  	  sum = sum - dita[i];
  }
  else if (cntb > lim) {
  	for (rint i = 1; i <= cntb - lim; i ++)
  	  sum = sum - ditb[i];
  }
  else {
  	for (rint i = 1; i <= cntc - lim; i ++)
  	  sum = sum - ditc[i];
  }

  cout << sum << '\n';
  return ;
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
  
  cin >> T;
  
  while (T --) solve ();

  return 0;
}
