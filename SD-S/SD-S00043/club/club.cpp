#include<bits/stdc++.h>
//#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=2e5+5;
int n,v[N],cnt;
struct node
{
	int a,b,c,mx,mi,mn;
}p[N];
bool cmp(node x,node y)
{
	if(x.mx-x.mi==y.mx-y.mi)return (x.mi-x.mn)>(y.mi-y.mn);
	return (x.mx-x.mi)>(y.mx-y.mi);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			p[i].a=read();p[i].b=read();p[i].c=read();
			p[i].mx=max(p[i].a,max(p[i].b,p[i].c));
			p[i].mn=min(p[i].a,min(p[i].b,p[i].c));
			p[i].mi=p[i].a+p[i].b+p[i].c-p[i].mx-p[i].mn;
		}
		sort(p+1,p+n+1,cmp);
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i].mx==p[i].a&&v[i]==0&&cnt1<n/2)
			{
				cnt1++;
				ans+=p[i].mx;
				v[i]=1;
			}
			if(p[i].mx==p[i].b&&v[i]==0&&cnt2<n/2)
			{
				cnt2++;
				ans+=p[i].mx;
				v[i]=1;
			}
			if(p[i].mx==p[i].c&&v[i]==0&&cnt3<n/2)
			{
				cnt3++;
				ans+=p[i].mx;
				v[i]=1;
			}
		}
		for(int i=1;i<=n;i++)if(v[i]==0)ans+=p[i].mi;
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)v[i]=0;
	}
	return 0;
}
