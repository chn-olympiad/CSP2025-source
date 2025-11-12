#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,tong[4],ans;
struct node
{
	int fir,sec,thir,cha,maxn,id;
}a[N];
bool cmp(node a,node b){return a.cha>b.cha;}
void init()
{
	ans=0;
	memset(a,0,sizeof(a));
	memset(tong,0,sizeof(tong));
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		init();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].fir>>a[i].sec>>a[i].thir;
			a[i].cha=2*max(a[i].fir,max(a[i].sec,a[i].thir))+min(a[i].fir,min(a[i].sec,a[i].thir))
						-a[i].fir-a[i].sec-a[i].thir;
			if(a[i].fir>=a[i].sec&&a[i].fir>=a[i].thir)a[i].maxn=a[i].fir,a[i].id=1;
			else if(a[i].sec>=a[i].thir)a[i].maxn=a[i].sec,a[i].id=2;
			else a[i].maxn=a[i].thir,a[i].id=3;
		}
		sort(a+1,a+n+1,cmp);
		int limit=n/2;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].maxn,tong[a[i].id]++;
			if(tong[a[i].id]>limit)tong[a[i].id]--,ans-=a[i].cha;
		}
		cout<<ans<<endl;
	}
	return 0;
}
