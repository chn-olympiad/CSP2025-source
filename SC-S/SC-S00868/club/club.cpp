#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=1e5+10;
//#define test
struct part
{
	int val;
	int id;
};
inline bool cmp(part a,part b)
{
	return a.val>b.val;
}
struct mem
{
	part pt[3];
	bool ava;//是否分配过 
	bool operator <(const mem& o)
	{
		return pt[0].val-pt[1].val>o.pt[0].val-o.pt[1].val;
	}
}p[MAX];
ll ans;
int t;
int n;
int num[3];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	#ifdef test
	freopen("club5.in","r",stdin);
//	freopen("club.out","w",stdout);
	#else
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	cin>>t;
	while(t--)
	{
		ans=0;
		num[0]=num[1]=num[2]=0;
//		cout<<num[0]<<num[1]<<num[2];
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i].pt[0].val>>p[i].pt[1].val>>p[i].pt[2].val,
			p[i].ava=1,p[i].pt[0].id=0,p[i].pt[1].id=1,p[i].pt[2].id=2,//初始化 
			sort(p[i].pt,p[i].pt+3,cmp);//排序 
		sort(p,p+n);
		for(int i=0;i<n;i++)
		{
			if(num[p[i].pt[0].id]<n/2)
				num[p[i].pt[0].id]++,ans+=p[i].pt[0].val,p[i].ava=0;
		}
		for(int i=0;i<n;i++)
		{
			if(p[i].ava&&num[p[i].pt[1].id]<n/2)
				num[p[i].pt[1].id]++,ans+=p[i].pt[1].val,p[i].ava=0;
		}
		cout<<ans<<'\n';
	}
}