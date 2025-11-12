#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x<y;
}
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,k,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			a[j]+=a[j+1];
		}
		if(a[j]/2==a[n])
		{
			ans++;
		}
	}
	ans%=998;
	ans%=244;
	ans%=353;
	cout<<ans;
	return 0;
}
