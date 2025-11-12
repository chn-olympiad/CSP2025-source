#include <bits/stdc++.h>
#define N 100100
using namespace std;

long long T,n,ans,top;

struct hg
{
	long long d1,d2,d3;
	bool vis;
}a[N];

long long mmax(long long x,long long y,long long z)
{
	long long maxm;
	maxm=max(x,y);
	maxm=max(maxm,z);
	return maxm;
}
bool cmp1(hg c,hg b){
	if (c.d1>b.d1) return 1;
	else return 0;
}
bool cmp2(hg c,hg b)
{
	if (c.d2>b.d2) return 1;
	else return 0;
}
bool cmp3(hg c,hg b)
{
	if(c.d3>b.d3) return 1;
	else return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>T;
	while(T--) 
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=N;++i)
		{
			a[i].vis=0;
			a[i].d1=a[i].d2=a[i].d3=0;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
		}
		top=n/2;
		long long cnt1,cnt2,cnt3;
		sort(a+1,a+n+1,cmp1);
		cnt1=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i].d1==mmax(a[i].d1,a[i].d2,a[i].d3) && !a[i].vis)
			{
				ans+=a[i].d1;
				a[i].vis=1;
				cnt1+=1;
			}
			if(cnt1==top) break;
		}
		sort(a+1,a+n+1,cmp2);
		cnt2=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i].d2==mmax(a[i].d1,a[i].d2,a[i].d3) && !a[i].vis)
			{
				ans+=a[i].d2;
				a[i].vis=1;
				cnt2++;
			}
			if(cnt2==top) break;
		}
		sort(a+1,a+n+1,cmp3);
		cnt3=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i].d3==mmax(a[i].d1,a[i].d2,a[i].d3) && !a[i].vis)
			{
				ans+=a[i].d3;
				a[i].vis=1;
				cnt3++;
			}
			if(cnt3==top) break;
		}
	
		cout<<ans<<"\n";
	}
	return 0;
}
