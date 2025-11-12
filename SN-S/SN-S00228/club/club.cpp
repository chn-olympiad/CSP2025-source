#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010];
long long t,n,ans,l1,l2,l3,now;
void dfs(long long d)
{
	if(d>n)
	{
		ans=max(ans,now);
		return;
	}
	if(l1+1<=n/2)
	{
		now+=a[d];
		l1++;
		dfs(d+1);
		now-=a[d];
		l1--;
	}
	if(l2+1<=n/2)
	{
		now+=b[d];
		l2++;
		dfs(d+1);
		now-=b[d];
		l2--;
	}
	if(l3+1<=n/2)
	{
		now+=c[d];
		l3++;
		dfs(d+1);
		now-=c[d];
		l3--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i]; 
		}
		l1=l2=l3=0;
		ans=0;
		now=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
