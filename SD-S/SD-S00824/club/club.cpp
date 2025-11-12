#include <bits/stdc++.h>
#define LL long long
#define pii pair<LL,int>
using namespace std;
const int N=1e5+100;
int t,n;
LL a[N][3],ans;
priority_queue<LL,vector<LL>,greater<LL> >pq[3];
int cnt0,cnt1,cnt2;
int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0LL;
		cnt0=cnt1=cnt2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			ans+=max(max(a[i][0],a[i][1]),a[i][2]); 
		}
		int nn=n/2;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) 
			{
				pq[0].push(a[i][0]-max(a[i][1],a[i][2]));
				cnt0++;
			}
			if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]) 
			{
				pq[1].push(a[i][1]-max(a[i][0],a[i][2]));
				cnt1++;
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][0])
			{
				pq[2].push(a[i][2]-max(a[i][1],a[i][0]));
				cnt2++;
			} 
		}
		if(cnt0>nn) 
		{
			while(cnt0>nn)
			{
				ans-=pq[0].top();pq[0].pop();
				cnt0--;
			}
		}
		else if(cnt1>nn) 
		{
			while(cnt1>nn)
			{
				ans-=pq[1].top();pq[1].pop();
				cnt1--;
			}
		}
		else if(cnt2>nn) 
		{
			while(cnt2>nn)
			{
				ans-=pq[2].top();pq[2].pop();
				cnt2--;
			}
		}
		printf("%lld\n",ans);
		while(pq[0].size()) pq[0].pop();
		while(pq[1].size()) pq[1].pop();
		while(pq[2].size()) pq[2].pop();
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
