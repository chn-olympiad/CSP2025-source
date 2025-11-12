#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+10;
int n,k,a[N] ,ans,arr[N],b[20];
string s;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		arr[i]=arr[i-1]+a[i];
	if(n<3)
		cout<<0;
	else if(n==3)
	{
		if(arr[2]>a[3])
			cout<<1;
		else
			cout<<0;
	}
	else if(n<=20)
	{
		while(b[n+1]==0)
		{
			int lg=1,x=1;
			while(lg)
			{
				b[x]++;
				lg=0;
				if(b[x]>=2)
				{
					lg++;
					b[x]=0;
					x++;
				}
			}
			int cnt=0,maxn=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i])
				{
					cnt+=a[i];
					maxn=max(a[i],maxn);
				}
			}
			if(maxn*2<cnt)
				ans++;
		}
		cout<<ans;
	}
	else
	{
		int lg=0;
		for(int i=1;i<=n;i++)
			if(a[i]>1)
				lg++;
		if(lg)
		{
			cout<<0;
		}
		else
		{
			int cnt;
			for(int i=3;i<=n;i++)
			{
				cnt=1;
				for(int j=0;j<i;j++)
				{
					cnt*=n-j;
				}
				for(int j=2;j<=i;j++)
				{
					cnt/=j;
				}
				ans+=cnt;
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
