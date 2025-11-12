#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
string a [N],b [N];
signed main ()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a [i] >> b [i];
	}
//q
	while (q --)
	{
		string s,t;
		cin >> s >> t;
		int ans = 0;
//n
		for (int i = 1;i <= n;i ++)
		{
			for (int l = 0;l < s.size () - a [i].size () + 1;l ++)
			{
				string x = s.substr (l,a [i].size ());
//				cout << x << endl;
				if (t.substr (l,b [i].size ()) == b [i] && x == a [i])
				{
					if (s.substr (0,l) == t.substr (0,l) && s.substr (l + a [i].size ()) == t.substr (l + b [i].size ())) ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}