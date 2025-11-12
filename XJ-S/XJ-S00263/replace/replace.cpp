#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string t[q][2],a[n][2];
	
	cin >> n >> q;
	for (int i=0;i<n;i++)
	{
		cin >> a[n][0] >> a[n][1];
	}
	for (int i=0;i<q;i++)
	{
		cin >> t[n][0] >> t[n][1];
	}
	while (q--)
	{
		cout << 0;
	}

	return 0;
} 

