# include <bits/stdc++.h>

using namespace std;

const long long N = 5e5 + 10;

long long n, k, pos, ans;
long long a[N], sum[N];

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("xor.in", "r", stdin);
  freopen ("xor.out", "w", stdout);

  cin >> n >> k;
  for (int i = 1; i <= n; i ++)
    cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
  pos = 0;
  for (int i = 1; i <= n; i ++)
  	for (int j = pos + 1; j <= i; j ++) {
  	  if ((sum[i] ^ sum[j - 1]) == k) {
  	    pos = i;
		ans ++;
		break;
	  }
	}
  cout << ans;
  return 0;
}

