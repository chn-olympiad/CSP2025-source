#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,sim,sm;
bool a;
int s[10006];
int xr,ans;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	xr=s[1];
	sort(s+1,s+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==xr)
		{
			ans=i;
			if(ans%n>0) ans+=n;
			cout<<ans/n<<" "<<y;
			return 0;
		}
		if(sim==1&&sm==0) sm++;
		else if(sim==1&&sm==1) y--;
		if(sim==0&&sm==1)sm=0;
		else if(sim==0&&sm==0) y++;
		if(y==n)
		{
			sim=1;
			a=1;
		}
		if(y==1&&a==1)
		{
			sim=0;
			sm=1;
			a=0;
		}
	}
}