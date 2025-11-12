#include<bits/stdc++.h>
using namespace std;
struct grade
{
	int a,b,c,n1,n2,cha;
}g[100005];
int t,n,num[4],x,cha[5]={0,999999999,999999999,999999999,0};
bool b;
long long ans;
bool cmp(grade d,grade e)
{
	return d.a>e.a;
}
bool cmp1(grade d,grade e)
{
	int y;
	if(d.cha==e.cha)
	{
		if(d.n1==1)	x=d.a;
		else if(d.n1==2)	x=d.b;
		else	x=d.c;
		if(e.n1==1)	y=e.a;
		else if(e.n1==2)	y=e.b;
		else	y=e.c;
		return x>y;
	}
	return d.cha>e.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0,num[1]=0,num[2]=0,num[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>g[i].a>>g[i].b>>g[i].c;
			if(g[i].c!=0||g[i].b!=0)b=1;
			if(g[i].a>g[i].b&&g[i].a>g[i].c)
			{
				g[i].n1=1;
				if(g[i].b>g[i].c)	g[i].n2=2,g[i].cha=g[i].a-g[i].b;
				else	g[i].n2=3,g[i].cha=g[i].a-g[i].c;
			}
			else if(g[i].b>g[i].a&&g[i].b>g[i].c)
			{
				g[i].n1=2;
				if(g[i].a>g[i].c)	g[i].n2=1,g[i].cha=g[i].b-g[i].a;
				else g[i].n2=3,g[i].cha=g[i].b-g[i].c;
			}
			else 
			{
				g[i].n1=3;
				if(g[i].b>g[i].a) g[i].n2=2,g[i].cha=g[i].c-g[i].b;
				else	g[i].n2=1,g[i].cha=g[i].c-g[i].a;
			}
		}
		if(!b)
		{
			sort(g+1,g+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=g[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(g+1,g+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(g[i].n1==1)	x=g[i].a;
			else if(g[i].n1==2)	x=g[i].b;
			else	x=g[i].c;
			if(num[g[i].n1]==n/2)
			{
				g[i].n1=g[i].n2;
				i--;
				continue;
			}
			else 
			{
				num[g[i].n1]++;
				ans+=x;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
