#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
struct node{ll a,b,c,d,e;}a[N],b;
ll t,n,s;
bool cmp(node x,node y)
{return x.a>y.a;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--)
	{
		cin>>n;s=0;bool o=0,h=0;b.a=b.b=b.c=0;
		for(ll i=1;i<=n;i++)
		{
			bool x=0;cin>>a[i].a>>a[i].b>>a[i].c;a[i].d=a[i].e=0;
			if(a[i].a>a[i].b&&a[i].a>a[i].c)s+=a[i].a,b.a++,x=1;
			if(a[i].b>a[i].a&&a[i].b>a[i].c)s+=a[i].b,b.b++,x=1;
			if(a[i].c>a[i].a&&a[i].c>a[i].b)s+=a[i].c,b.c++,x=1;
			if(!x)s+=max(a[i].a,max(a[i].b,a[i].c));
			if(b.a>n/2||b.b>n/2||b.c>n/2)o=1;if(a[i].b)h=1;
		}
		if(!h)
		{
			s=0;sort(a+1,a+n+1,cmp);
			for(ll i=1;i<=n/2;i++)s+=a[i].a;
			cout<<s<<endl;continue;
		}
		if(!o)cout<<s<<endl;
		else 
		{
			b.a=b.b=b.c=s=0;
			for(ll i=1,x,y;i<=n;i++)
			{
				x=max(a[i].a,max(a[i].b,a[i].c));
				if(x==a[i].a)a[i].e=1;if(x==a[i].b)a[i].e=2;if(x==a[i].c)a[i].e=3;
			}
			for(ll i=1,x,y;i<=n;i++)
			{
				x=max(a[i].a,max(a[i].b,a[i].c));
				y=a[i].a+a[i].b+a[i].c-min(a[i].a,min(a[i].b,a[i].c))-x;
				a[i].d=x-y;
				if(a[i].a==x&&b.a<n/2){s+=x;b.a++;}
				else if(a[i].b==x&&b.b<n/2){s+=x;b.b++;}
				else if(a[i].c==x&&b.c<n/2){s+=x;b.c++;}
				else
				{
					ll l=INT_MAX,p;
					for(ll j=1;j<i;j++)if(a[j].d<l&&a[j].e==a[i].e)l=a[j].d,p=j;
					if(s+y>s+x-l)s=s+y,a[i].d=INT_MAX;
					else s=s+x-l,a[p].d=INT_MAX;
				}
			}
			cout<<s<<endl;
		}
	}
	return 0; 
}
