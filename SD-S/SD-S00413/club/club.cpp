#include<bits/stdc++.h>

using namespace std;
int t;
struct node
{
	int f,s,t;
	bool b;
	int al;
}a[110000];
bool cmp1(node a,node b)
{
	return a.f>b.f;
}
bool cmp2(node a,node b)
{
	return a.s>b.s;
}
bool cmp3(node a,node b)
{
	return a.t>b.t;
}
int ans;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		int n;
//		struct node
//		{
//			int f,s,t;
//			bool b[110000];
//			int al[110000];
//		}a[110000];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			a[i].b=0;
			a[i].al=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		int maxn=n/2;
		sort(a+1,a+n+1,cmp1);//按最多取
		for(int i=1;i<=maxn;i++)
		{
			ans+=a[i].f;
			a[i].b=1;
			a[i].al=a[i].f;
		}
		sort(a+1,a+n+1,cmp2);
		int maxn2;
		int cnt=n-maxn;
		if(cnt>=maxn)
		{
			maxn2=maxn;
		}
		else
		{
			maxn2=cnt;
		}
//		int maxn2=maxn;
		for(int i=1;i<=maxn2;i++)
		{
			if(a[i].b==1)//已被选 
			{
				if(a[i].al<a[i].s)
				{
					ans-=a[i].al;
					ans+=a[i].s;
					a[i].al=a[i].s;
				}
				if(a[i].al>=a[i].s)
				{
					i-=1;//注意总量 
					continue;
				}
			}
			else
			{
				a[i].b=1;
				a[i].al=a[i].s;
				ans+=a[i].s;
			}
		}
		sort(a+1,a+n+1,cmp3);
		int maxn3;
		int cnt2=n-maxn-maxn2;
		if(cnt2>0)
		{
			maxn3=cnt2;
		}
		else
		{
			maxn3=n;
		}
		int num=0;
		for(int i=1;i<=maxn3;i++)
		{
			if(num>maxn) break;
			if(a[i].b==1)//已被选 
			{
				if(a[i].al<a[i].t)
				{
					ans-=a[i].al;
					ans+=a[i].t;
					a[i].al=a[i].t;
					num++;
				}
				if(a[i].al>=a[i].t)
				{
					i-=1;//注意总量 
					continue;
				}
			}
			else
			{
				a[i].b=1;
				a[i].al=a[i].t;
				ans+=a[i].t;
				num++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
