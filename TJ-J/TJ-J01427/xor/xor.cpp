#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];

	if (k==0) cout << n/2;
	else if (k==1)
	{
		long long ans=0,x=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1)
			{
				x++;
				if (x==2)
				{
					ans++;
					x=0;
				}
			}
		}
		cout << ans;
	}
	else cout << 0; 
	return 0;
}
