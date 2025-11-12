#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010];
int ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==k) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		int d=a[i];
		for(int j=i;j<=n;j++)
		{
			d^=a[j];
			if(d==k)
			{
				//cout << "这是第" << i<<"个,j为"<<j<<'\n';
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
