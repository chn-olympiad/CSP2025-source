#include <bits/stdc++.h>
using namespace std;
int n,a[5001],aa[5001],qm=998244353,ans=0;
int q(int tk)
{
	int llans=0;
	if(tk<3)
	{
		int hkjh=1;
		return hkjh;
	}
	if(aa[tk]!=0)
	{
		return aa[tk];
	}
	for(int i=1;i<=tk;i++)
	{
		for(int j=i+1;j<=tk;j++)
		{
			if(a[i]+a[j]>a[tk])
			{
				llans+=q(i)+q(j);
				llans%=qm;
			}
		}
	}
	aa[tk]=llans;
	return aa[tk];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		ans+=q(i);
		ans%=qm;
	}
	cout<<ans;
	return 0;
}
