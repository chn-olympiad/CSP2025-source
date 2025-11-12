#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,a[N][5],f[N],T,F[N];
struct node
{
	ll a,i;
}t[N];
bool cmp(node n,node m)
{
	return n.a>m.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		ll fst,sec,trd;
		fst=sec=trd=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i][1]);
			scanf("%lld",&a[i][2]);
			scanf("%lld",&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])fst++,f[i]=1;
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])sec++,f[i]=2;
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])trd++,f[i]=3;
		}/*
		if(T==0)
		{
			sort(F+1,F+n+1);
			ll ans=0;
			for(int i=n;i>n/2;i++)ans+=F[i];
			printf("%lld\n",ans);
			continue;
		}*/
		if(fst<=n/2&&sec<=n/2&&trd<=n/2)
		{
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][f[i]];
			}
			printf("%lld\n",ans);
		}
		else
		{
			ll x,y;
			if(fst>n/2)x=1,y=fst;
			if(sec>n/2)x=2,y=sec;
			if(trd>n/2)x=3,y=trd;
			//cout<<x<<" "<<y<<endl;
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				t[i].a=0;
				if(f[i]!=x)
				{
					ans+=a[i][f[i]];
					continue;
				}
				if(x==1)t[i].a=a[i][1]-max(a[i][2],a[i][3]);
				if(x==2)t[i].a=a[i][2]-max(a[i][1],a[i][3]);
				if(x==3)t[i].a=a[i][3]-max(a[i][1],a[i][2]);
				t[i].i=i;
				//cout<<":::"<<i<<" "<<t[i].i<<" "<<t[i].a<<endl;
			}
			sort(t+1,t+n+1,cmp);
			for(int i=1;i<=y;i++)
			{
				//cout<<"???"<<t[i].i<<" "<<a[t[i].i][x]<<" "<<t[i].a<<endl;
				if(i<=n/2)ans+=a[t[i].i][x];
				else 
				{
					if(x==1)ans+=max(a[t[i].i][2],a[t[i].i][3]);
					if(x==2)ans+=max(a[t[i].i][1],a[t[i].i][3]);
					if(x==3)ans+=max(a[t[i].i][2],a[t[i].i][1]);
				}
			}
			printf("%lld\n",ans);
		}
	}
}