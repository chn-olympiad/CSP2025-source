#include<bits/stdc++.h>
using namespace std;
int n,a[100006],mmax,sum,ans;
void dfs(int shu)
{
	int xuan,s[100006];
	for(int i=1;i<=shu;i++)
	{
		mmax=0;
		sum=0;
		xuan++;
		s[i]=a[i];
		if(xuan==shu)
		{
			for(int j=1;j<=n;j++)
			{
				mmax=max(mmax,s[j]);
				sum+=s[j];
			}
			if(mmax*2<sum) ans++;
		}
		if(shu<n)
		{
			dfs(shu+1);
			xuan--;
			s[i]=0;

		}


	}

}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mmax=max(mmax,s[j]);
		sum+=s[j];
	}
	if(n==3)
	{
		if(2*mmax<sum) cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(3);
	cout<<ans%998244353;
	return 0;
}