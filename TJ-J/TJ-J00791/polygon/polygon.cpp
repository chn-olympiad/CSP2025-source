#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxx,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	maxx=-100000;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n<=3)
	{
		sum+=a[1];
		sum+=a[2];
		sum+=a[3];
		maxx=max(a[1],max(a[2],a[3]));
		if(sum>2*maxx) ans++;
		cout << ans;
		return 0;
	}
	else{
		for(int i=n-2;i>=1;i--)
		{
			ans+=i;
		}
		cout << ans;
	}
	return 0;
}
