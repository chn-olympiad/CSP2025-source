#include<bits/stdc++.h>
#define int long long
using namespace std;
struct per{
	int a,b,c;
	bool operator >(const per t) const{
		return max(max(a,b),c)*2+min(min(a,b),c)-a-b-c>max(max(t.a,t.b),t.c)*2+min(min(t.a,t.b),t.c)-t.a-t.b-t.c;
	}
};
priority_queue<per,vector<per>,greater<per> > pq[4];
int pm1,pm2,pm3;
int now1,now2,now3;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			int mx=max(a,max(b,c));
			if(a==mx) {pq[1].push({a,b,c});pm1+=a;now1++;}
			else if(b==mx) {pq[2].push({a,b,c});pm2+=b;now2++;}
			else if(c==mx) {pq[3].push({a,b,c});pm3+=c;now3++;}
		}
		if(now1>(n/2))
		{
			int val=now1-(n/2);
			for(int i=1;i<=val;i++)
			{
				per tp=pq[1].top();
				pq[1].pop();
				if(tp.b>tp.c)
				{
					pq[2].push(tp);
					pm1-=tp.a;
					now1--;
					pm2+=tp.b;
					now2++;
				}
				else if(tp.c>=tp.b)
				{
					pq[3].push(tp);
					pm1-=tp.a;
					now1--;
					pm3+=tp.c;
					now3++;
				}
			}
		}
		else if(now2>(n/2))
		{
			int val=now2-(n/2);
			for(int i=1;i<=val;i++)
			{
				per tp=pq[2].top();
				pq[2].pop();
				if(tp.a>tp.c)
				{
					pq[1].push(tp);
					pm2-=tp.b;
					now2--;
					pm1+=tp.a;
					now1++;
				}
				else if(tp.c>=tp.a)
				{
					pq[3].push(tp);
					pm2-=tp.b;
					now2--;
					pm3+=tp.c;
					now3++;
				}
			}
		}
		else if(now3>(n/2))
		{
			int val=now3-(n/2);
			for(int i=1;i<=val;i++)
			{
				per tp=pq[3].top();
				pq[3].pop();
				if(tp.a>tp.b)
				{
					pq[1].push(tp);
					pm3-=tp.c;
					now3--;
					pm1+=tp.a;
					now1++;
				}
				else if(tp.b>=tp.a)
				{
					pq[2].push(tp);
					pm3-=tp.c;
					now3--;
					pm2+=tp.b;
					now2++;
				}
			}
		}
		cout<<pm1+pm2+pm3<<endl;
		while(!pq[1].empty()) pq[1].pop();
		while(!pq[2].empty()) pq[2].pop();
		while(!pq[3].empty()) pq[3].pop();
		pm1=0,pm2=0,pm3=0;
		now1=0,now2=0,now3=0;
	}
	
	return 0;
}