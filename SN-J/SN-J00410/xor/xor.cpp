#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n, k, l=1, r, ans;
ll a[500005];
bool lst[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	r=n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]==k)
		{
			ans++,lst[i]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		bool flg=0;
		l=1,r=l+i;
		for (int i=1;i<=n;i++)
		{
			if (lst[i]==0)
			{
				flg=1;
				break; 
			}
		}
		if (flg==0) break;
		while (r<=n)
		{
			if (lst[l]==1) 
			{
				l++,r++;
				continue;
			}
			ll ansx=a[l];
			bool flag=1;
			for (int j=l+1;j<=r;j++)
			{
				if (lst[j]==1)
				{
					flag=0;
					break;
				} 
				ansx^=a[j];
			}
			if (ansx==k&&flag==1)
			{
				ans++;
				l+=i, r+=i;
				for (int j=l;j<=r;j++) lst[j]=1;
			}
			l++,r++;
		}
	}
	cout << ans;
}
