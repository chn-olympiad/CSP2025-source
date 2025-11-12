#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
struct P
{
	int a,b,c;
	int id1,id2,id3;
	bool operator<(P x)const
	{
		return a-b<x.a-x.b;
	}
}a[N];
vector<P> c[4];
void solve()
{
	ans=0;
	c[1].clear();
	c[2].clear();
	c[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		a[i].id1=1,a[i].id2=2,a[i].id3=3;
		if(a[i].b<a[i].c)
		{
			swap(a[i].b,a[i].c);
			swap(a[i].id2,a[i].id3);
		}
		if(a[i].a<a[i].b)
		{
			swap(a[i].a,a[i].b);
			swap(a[i].id1,a[i].id2);
		}
		if(a[i].b<a[i].c)
		{
			swap(a[i].b,a[i].c);
			swap(a[i].id2,a[i].id3);
		}
		c[a[i].id1].push_back(a[i]);
		ans+=a[i].a;
	} 
	if(c[1].size()>n/2)
	{
		sort(c[1].begin(),c[1].end());
		int t=0;
		while(c[1].size()-t>n/2)
		{
			ans-=c[1][t].a-c[1][t].b;
			t++;
		}
	}
	else if(c[2].size()>n/2)
	{
		sort(c[2].begin(),c[2].end());
		int t=0;
		while(c[2].size()-t>n/2)
		{
			ans-=c[2][t].a-c[2][t].b;
			t++;
		}
	} 
	else if(c[3].size()>n/2)
	{
		sort(c[3].begin(),c[3].end());
		int t=0;
		while(c[3].size()-t>n/2)
		{
			ans-=c[3][t].a-c[3][t].b;
			t++;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}
