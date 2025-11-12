//15:03
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int T;
int n;
struct node{
	int x,y,z;
}a[N];
struct afo{
	int mx,mxp;
	int mi,mip;
	int d;
}b[N];
int ans=0;
int vis[5];
void work(int x)
{
	if(a[x].x>=a[x].y&&a[x].x>=a[x].z)
	{
		b[x].mx=a[x].x;
		b[x].mxp=1;
		if(a[x].y>a[x].z)
		{
			b[x].mi=a[x].y;
			b[x].mip=2;
		}else{
			b[x].mi=a[x].z;
			b[x].mip=3;
		}
		b[x].d=b[x].mx-b[x].mi;
		return ;
	}
	if(a[x].y>=a[x].x&&a[x].y>=a[x].z)
	{
		b[x].mx=a[x].y;
		b[x].mxp=2;
		if(a[x].x>a[x].z)
		{
			b[x].mi=a[x].x;
			b[x].mip=1;
		}else{
			b[x].mi=a[x].z;
			b[x].mip=3;
		}
		b[x].d=b[x].mx-b[x].mi;
		return ;
	}
	if(a[x].z>=a[x].y&&a[x].z>=a[x].x)
	{
		b[x].mx=a[x].z;
		b[x].mxp=3;
		if(a[x].y>a[x].x)
		{
			b[x].mi=a[x].y;
			b[x].mip=2;
		}else{
			b[x].mi=a[x].x;
			b[x].mip=1;
		}
		b[x].d=b[x].mx-b[x].mi;
		return ;
	}
}
bool cmp(afo p1,afo p2)
{
	return p1.d<p2.d;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(vis,0,sizeof vis);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++)
		{
			work(i);
			ans+=b[i].mx;
			vis[b[i].mxp]++;
		}
		sort(b+1,b+1+n,cmp);
		int m=n/2;
		for(int i=1;i<=n;i++)
		{
			if(vis[b[i].mxp]>m)
			{
				ans-=b[i].d;
				vis[b[i].mxp]--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

