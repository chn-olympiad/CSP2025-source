#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int X=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=X*10+(ch-'0'); ch=getchar();}
	return X*f;
}
int n,a[100005][3],t[100005],ans,b[100005];
void solve(int id)
{
	int as=0;
	for(int i=1;i<=n;i++)
	{
		if(id==0)b[i]=a[i][id]-max(a[i][1],a[i][2]);
		if(id==1)b[i]=a[i][id]-max(a[i][0],a[i][2]);
		if(id==2)b[i]=a[i][id]-max(a[i][1],a[i][0]);
		as+=a[i][id];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n/2;i++)
	{
		as-=b[i];
	}
	ans=max(ans,as);
}
void work()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		int maxx=max(max(a[i][0],a[i][1]),a[i][2]);
		for(int j=0;j<3;j++) 
		{
			if(a[i][j]==maxx)
			{
				t[j]++;
			}
		}
		ans+=maxx;
	}
	if(!(t[0]<=n/2&&t[1]<=n/2&&t[2]<=n/2))
	{
		ans=0;
	}
	t[0]=t[1]=t[2]=0;
	solve(0);
	solve(1);
	solve(2);
	cout<<ans<<'\n';
	ans=0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt=read();
	while(tt--) work();
	return 0;
} 