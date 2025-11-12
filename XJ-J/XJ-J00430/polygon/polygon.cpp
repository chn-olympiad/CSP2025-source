#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],sum,M=998244353,t,n,num;
void zx(int s,int tt)
{
	if(s>t)
	{
		if(num>b[t]*2)
		{
			sum++;
			sum%=M;
		}
		return ;
	}
	for(int i=tt;i<=n;i++)
	{
		b[s]=a[i];
		num+=a[i];
		zx(s+1,i+1);
		num-=a[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(i=3;i<=n;i++)
	{
		t=i;num=0;
		zx(1,1);
	}
	cout<<sum%M;
	return 0;
}
