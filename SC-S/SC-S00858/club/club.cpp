#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans=0,a,b,c;
struct mmx
{
	int x,y,z;
}s[200005];
priority_queue<pair<int,int>>q[3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=a=b=c=0;
		for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y>>s[i].z;
		for(int i=1;i<=n;i++)
		{
			int A=s[i].x,B=s[i].y,C=s[i].z;
			if(C>=B&&C>=A) q[2].push({max(A,B)-C,i}),c++,ans+=C;
			else if(B>=C&&B>=A) q[1].push({max(A,C)-B,i}),b++,ans+=B;
			else q[0].push({max(C,B)-A,i}),a++,ans+=A;
		}
		while(c*2>n)
		{
			ans+=q[2].top().first;
			c--;
			q[2].pop();
		}
		while(b*2>n)
		{
			ans+=q[1].top().first;
			b--;
			q[1].pop();
		}
		while(a*2>n)
		{
			ans+=q[0].top().first;
			a--;
			q[0].pop();
		}
		cout<<ans<<"\n";
		while(!q[0].empty()) 
			q[0].pop(); 
		while(!q[1].empty()) 
			q[1].pop(); 
		while(!q[2].empty()) 
			q[2].pop(); 
	}
	return 0;
}