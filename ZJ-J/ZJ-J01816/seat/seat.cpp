#include<bits/stdc++.h>
using namespace std;
int a[111],mp[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int t = a[1],pos = 0;
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i = 1;i <= m;i++)
	{
		if(i%2)
		{
			for(int j = 1;j <= n;j++)
			{
				mp[j][i] = a[++pos];
				if(a[pos] == t)
				{
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				mp[j][i] = a[++pos];
				if(a[pos] == t)
				{
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
