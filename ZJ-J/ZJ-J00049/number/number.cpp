# include <bits/stdc++.h>

using namespace std;

string str;
long long len;

inline void solve (char x) {
  for (int i = 0; i <= len; i ++)
    if (str[i] == x) cout << x;
  return ;	
}

signed main () {

  ios::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);
  
  freopen ("number.in", "r", stdin);
  freopen ("number.out", "w", stdout);
  
  cin >> str;
  
  len = str.size () - 1;
  
  for (char i = '9'; i >= '0'; i --)
    solve (i);
  
  return 0;
}

