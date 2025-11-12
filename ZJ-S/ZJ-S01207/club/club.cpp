#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans,a[100005][5];	
priority_queue<ll,vector<ll>,greater<ll> > A[8],b[8],c[8];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][1]>=max(a[i][2],a[i][3]))
				A[t].push(a[i][1]-max(a[i][2],a[i][3])),ans+=a[i][1];
			else if(a[i][2]>=max(a[i][1],a[i][3]))
				b[t].push(a[i][2]-max(a[i][1],a[i][3])),ans+=a[i][2];
			else if(a[i][3]>=max(a[i][2],a[i][1]))
				c[t].push(a[i][3]-max(a[i][2],a[i][1])),ans+=a[i][3];
		}
		if(A[t].size()*2>n)
		{
			while(A[t].size()*2>n)
			{
				ans-=A[t].top();
				A[t].pop();
			}
		}
		if(b[t].size()*2>n)
		{
			while(b[t].size()*2>n)
			{
				ans-=b[t].top();
				b[t].pop();
			}
		}
		if(c[t].size()*2>n)
		{
			while(c[t].size()*2>n)
			{
				ans-=c[t].top();
				c[t].pop();
			}
		}
		cout<<ans<<'\n';
		ans = 0;
	}
	return 0;
}