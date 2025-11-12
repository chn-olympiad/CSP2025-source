#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a,b,c,cnta,cntb,cntc,ans;
priority_queue<pair<int,int> > q;
void solve()
{
	cin>>n;
	while(q.size()) q.pop();
	cnta=cntb=cntc=ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(a>=b&&b>=c) cnta++,q.push({-a+b,0});
		else if(a>=c&&c>=b) cnta++,q.push({-a+c,0});
		else if(b>=a&&a>=c) cntb++,q.push({-b+a,1});
		else if(b>=c&&c>=a) cntb++,q.push({-b+c,1});
		else if(c>=a&&a>=b) cntc++,q.push({-c+a,2});
		else if(c>=b&&b>=a) cntc++,q.push({-c+b,2});
		ans+=max(a,max(b,c));
	}
	if(cnta>n/2)
	{
		while(q.size()&&cnta>n/2)
		{
			if(q.top().second==0)
			{
				cnta--;
				ans+=q.top().first;
			}
			q.pop();
		}
	}
	if(cntb>n/2)
	{
		while(q.size()&&cntb>n/2)
		{
			if(q.top().second==1)
			{
				cntb--;
				ans+=q.top().first;
			}
			q.pop();
		}
	}
	if(cntc>n/2)
	{
		while(q.size()&&cntc>n/2)
		{
			if(q.top().second==2)
			{
				cntc--;
				ans+=q.top().first;
			}
			q.pop();
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
/*
一眼哩 
对于每个人，我们先把他分配到其好感最高的地方，
然后记录转行后好感变化最小差及每个岗位有多少人。
对于每个岗位分别判断，如果大于一半，则将好感变化
差最小的多余的人弹出，答案减去差即可 
*/