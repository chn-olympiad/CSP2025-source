#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
	ll x,y,z;
};
const ll N=100010;
ll t,n,cntx,cnty,cntz,ans;
st a[N],nw[N],x[N],y[N],z[N];
bool cmpx(st x,st y)
{
	return x.x-max(x.y,x.z)>y.x-max(y.y,y.z);
}
bool cmpy(st x,st y)
{
	return x.y-x.z>y.y-y.z;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cntx=0,cnty=0,cntz=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=max(a[i].y,a[i].z))
			{
				cntx++;
			}
			else if(a[i].y>=max(a[i].x,a[i].z))
			{
				cnty++;
			}
			else
			{
				cntz++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(cntx>=cnty&&cnty>=cntz)
			{
				nw[i]={a[i].x,a[i].y,a[i].z};
			}
			else if(cntx>=cntz&&cntz>=cnty)
			{
				nw[i]={a[i].x,a[i].z,a[i].y};
			}
			else if(cnty>=cntx&&cntx>=cntz)
			{
				nw[i]={a[i].y,a[i].x,a[i].z};
			}
			else if(cnty>=cntz&&cntz>=cntx)
			{
				nw[i]={a[i].y,a[i].z,a[i].x};
			}
			else if(cntz>=cntx&&cntx>=cnty)
			{
				nw[i]={a[i].z,a[i].x,a[i].y};
			}
			else if(cntz>=cnty&&cnty>=cntx)
			{
				nw[i]={a[i].z,a[i].y,a[i].x};
			}
		}
		cntx=0,cnty=0,cntz=0;
		for(int i=1;i<=n;i++)
		{
			if(nw[i].x>=max(nw[i].y,nw[i].z))
			{
				x[++cntx]=nw[i];
			}
			else if(nw[i].y>=max(nw[i].x,nw[i].z))
			{
				y[++cnty]=nw[i];
			}
			else
			{
				z[++cntz]=nw[i];
			}
			ans+=max(nw[i].x,max(nw[i].y,nw[i].z));
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<nw[i].x<<" "<<nw[i].y<<" "<<nw[i].z<<"\n";
//		}
		if(cntx>n/2)
		{
			sort(x+1,x+cntx+1,cmpx);
			for(int i=cntx;i>=n/2+1;i--)
			{
				ans-=x[i].x-max(x[i].y,x[i].z);
				if(x[i].y>=x[i].z)
				{
					y[++cnty]=x[i];
				}
				else
				{
					z[++cntz]=x[i];
				}
			}
			cntx=n/2;
		}
		if(cnty>n/2)
		{
			sort(y+1,y+cnty+1,cmpy);
			for(int i=cnty;i>=n/2+1;i--)
			{
				ans-=y[i].y-y[i].z;
				z[++cntz]=y[i];
			}
			cnty=n/2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}