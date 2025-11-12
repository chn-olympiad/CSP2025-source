#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+1;
ll t,ans;
ll n,x[4];
struct nod
{
	ll b[4],a[4],m;
	ll id1,id2;
}p[N];
bool cmp(ll a,ll b)
{
	return a>b;
}
bool cmp1(nod a, nod b)
{
	if(a.m==b.m) 
	{
		if(a.a[1]==b.a[1]) return a.a[2]>=b.a[2];
		return a.a[1]>b.a[1];
	}
	return a.m>b.m;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(x,0,sizeof x);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			p[i].b[1]=p[i].a[1],p[i].b[2]=p[i].a[2],p[i].b[3]=p[i].a[3];
			sort(p[i].a+1,p[i].a+4,cmp);
			p[i].m=p[i].a[1]-p[i].a[2];
			for(int j=1;j<=3;j++)
			{
				if(p[i].a[1]==p[i].b[j])p[i].id1=j;
				if(p[i].a[2]==p[i].b[j])p[i].id2=j;
			}
		}
		sort(p+1,p+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(x[p[i].id1]+1<=n/2)
			{
				x[p[i].id1]++;
				ans+=p[i].a[1];
			}
			else if(x[p[i].id2]+1<=n/2)
			{
				x[p[i].id2]++;
				ans+=p[i].a[2];
			}else {
				ans+=p[i].a[3];
				x[6-p[i].id2-p[i].id1]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/