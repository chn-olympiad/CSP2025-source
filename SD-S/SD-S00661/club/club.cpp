#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5,X=2e4;
long long T,n,ans,t[3],C=1;
struct node
{
	long long w,x;
}a[N],b[N],c[N];
struct Node
{
	long long a,b,c;
	long long maxa,maxb,maxc;
}s[N];
long long cmp(node a,node b)
{
	if(a.w==b.w)return a.x<b.x;
	return a.w>b.w;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		cin>>n;
		long long k=n>>1,f=0;
		for(long long i=1;i<=n;i++)
		{
			long long x,y,z;
			cin>>x>>y>>z;
			if(!((x==0||x==X)&&(y==0||y==X)&&(z==0||z==X)))C=0;
			s[i].a=x,s[i].b=y,s[i].c=z;
			s[i].maxa=max(y,z),s[i].maxb=max(x,z),s[i].maxc=max(x,y);
			a[i].w=x,b[i].w=y,c[i].w=z;
			a[i].x=b[i].x=c[i].x=i;
			if(x>y&&x>z)
			{
				t[1]++;
				ans+=x;
				if(t[1]>k)f=1;
			}
			if(y>x&&y>z)
			{
				t[2]++;
				ans+=y;
				if(t[2]>k)f=1;
			}
			if(z>y&&z>x)
			{
				t[3]++;
				ans+=z;
				if(t[3]>k)f=1;
			}
		}
		if(f==0)
		{
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		long long sum=0;
		for(long long i=1;i<=k;i++)
		{
			sum+=a[i].w;
		}
		for(long long i=k+1;i<=n;i++)
		{
			sum+=s[a[i].x].maxa;
		}
		ans=sum;
		sum=0;
		for(long long i=1;i<=k;i++)
		{
			sum+=b[i].w;
		}
		for(long long i=k+1;i<=n;i++)
		{
			sum+=s[b[i].x].maxb;
		}
		ans=max(ans,sum);
		sum=0;
		for(long long i=1;i<=k;i++)
		{
			sum+=c[i].w;
		}
		for(long long i=k+1;i<=n;i++)
		{
			sum+=s[c[i].x].maxc;
		}
		ans=max(ans,sum);
		cout<<ans<<"\n";
	}
	return 0;
}
