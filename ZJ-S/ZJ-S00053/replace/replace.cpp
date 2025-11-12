# include <bits/stdc++.h>

# define int long long
# define rint register int

using namespace std;

const int N = 2e5 + 10;
const int V = 1e7 + 10;
const int W = 6e6 + 2;

string a[N], b[N];
string str1, str2, str3;
int n, q, ans;
int vis[V];

inline void solve () {
  ans = 0;
  for (rint i = 1; i <= n; i ++) {
  	for (rint j = 0; j < str1.size (); j ++) {
  	  while (a[i][0] != str1[j] && j < str1.size ()) j ++;
  	  int k = 0;
  	  bool f = true;
      str3 = str1;
  	  while (a[i][k] == str1[j]) {
	    str3[j] = b[i][k];
	    k ++, j ++;
		if (k == a[i].size ()) {
  	      f = false;
		  break;
	    }
	  }
	  if (f == false && str3 == str2) ans ++;
	  str3 = str1;
	}
  }
  cout << ans << endl;
  return ;
}

inline bool check () {
  int cnt = 0, cnt1 = 0;
  for (rint i = 1; i <= n; i ++) {
  	for (rint j = 0; j < a[i].size (); j ++) {
  	  if (a[i][j] == 'b') cnt ++;
  	  if (b[i][j] == 'b') cnt1 ++;
  	  if ((a[i][j] != 'a' && a[i][j] != 'b') || (b[i][j] != 'a' && b[i][j] != 'b')) return false;
    }
  if (cnt != 1 || cnt1 != 1) return false;
  }
  return true;
}

inline void qwq () {
  int pos1, pos2;
  for (rint i = 1; i <= n; i ++) {
  	pos1 = 0, pos2 = 0;
  	for (rint j = 0; j < a[i].size (); j ++) {
  	  if (a[i][j] == 'b') pos1 = j;
	  if (b[i][j] == 'b') pos2 = j;
	  if (pos1 && pos2) break; 
	}
	vis[pos2 - pos1 + W] ++; 
  }
  while (q --) {
  	cin >> str1 >> str2;
  	pos1 = 0, pos2 = 0;
  	for (rint j = 0; j < str1.size (); j ++) {
  	  if (str1[j] == 'b') pos1 = j;
	  if (str2[j] == 'b') pos2 = j;
	  if (pos1 && pos2) break;
	}
	ans = vis[pos2 - pos1 + W];
	cout << ans << endl;
  }
  return ;
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("replace.in", "r", stdin);
  freopen ("replace.out", "w", stdout);
  
  cin >> n >> q;

  for (rint i = 1; i <= n; i ++)
  	cin >> a[i] >> b[i];
  
  if (check ()) {
  	qwq ();
  	return 0;
  }
  
  while (q --) {
    cin >> str1 >> str2;
  	solve ();
  }

  
  return 0;
}
