//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
char s[1000006] , c;
int cnt;
int main ()
{
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	while (cin >> c)
		if (c >= '0' && c <= '9') s[++ cnt] = c;
	sort (s + 1 , s + cnt + 1);
	for (int i = cnt;i >= 1;i --) cout << s[i];
	return 0;
}
