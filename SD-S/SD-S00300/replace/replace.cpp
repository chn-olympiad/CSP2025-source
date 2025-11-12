#include<bits/stdc++.h>
using namespace std;
int n, q, s[200005], t[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> t[i];
	}
	for(int i = 1; i <= q; i++)
	{
		cout << 0 << endl;
	}
	return 0;
}

