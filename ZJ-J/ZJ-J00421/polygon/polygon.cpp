#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int a[5005],m[5001];
int read()
{
	int i=0;
	char j;
	j=getchar();
	while(j<'0'||j>'9') j=getchar();
	while(j>='0'&&j<='9')
	{
		i=i*10+j-'0';
		j=getchar();
	}
	return i;
}
int n;
int uni(int bs,int ma,int he,int i)
{
	if(bs<3&&i==n)
	{
		return 0;
	}
	else if(i==n)
	{
		if(he>2*ma) return 1;
		else return 0;
	}
	else return (uni(bs+1,max(ma,a[i+1]),he+a[i+1],i+1)+uni(bs,ma,he,i+1))%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	bool o=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==1&&o) o=1;
		else o=0;
	} 
	int ans=0;
	if(n==3)
	{
		int o=max(a[1],max(a[2],a[3]));
		int oi=a[1]+a[2]+a[3];
		if(oi>2*o) ans=1;
		else ans=0;
	}
	else if(n<=25)
	{
		ans=uni(1,a[1],a[1],1)%mod+uni(0,0,0,1)%mod;
	}
	else if(o)
	{
		m[1]=n;
		for(int i=2;i<=n;i++)
		{
			for(int j=i+1;j<=m[i-1];j++)
			{
				m[i]+=j;
				m[i]%=mod;
			}
			cout<<m[i]<<' ';
			if(i>=3)
			{
				ans+=m[i]-1;
				ans%=mod;
			} 
		}
		cout<<endl;
	}
	else ans=uni(1,a[1],a[1],1)%mod+uni(0,0,0,1)%mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//20
//75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
