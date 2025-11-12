#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,sum,maxn;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum=0;
		maxn=0;
		for (int j=i;j<=i+3;j++) maxn=max(maxn,a[j]);
		for (int j=i+3;j<=n;j++)
		{
			sum+=a[j];
			maxn=max(a[j],maxn);
			if (sum<=2*maxn) break;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
