#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100][4],vis[4];
long long sum;
priority_queue<pair<int,int> >q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		vis[1]=vis[2]=vis[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int c=max(a[i][1],max(a[i][2],a[i][3]));
			int d=a[i][1]+a[i][2]+a[i][3]-c-min(a[i][1],min(a[i][2],a[i][3]));
			sum+=c;
			int k=0;
			if(c==a[i][1])k=1;
			if(c==a[i][2])k=2;
			if(c==a[i][3])k=3;
			q.push(make_pair(c-d,k));
		}
		while(!q.empty())
		{
			int c=q.top().first;
			int d=q.top().second;
			q.pop();
			if(vis[d]==n/2)
			{
				sum-=c;
			}
			else
			{
				vis[d]++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}

