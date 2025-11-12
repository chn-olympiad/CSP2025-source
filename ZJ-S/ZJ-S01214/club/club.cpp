#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n;
int v[N][3];
int Max[3];
long long ans=0;
priority_queue<int>q;
void fre()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		Max[0]=Max[1]=Max[2]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i][0]>>v[i][1]>>v[i][2];
			ans+=max(max(v[i][0],v[i][1]),v[i][2]);
			if(v[i][0]>v[i][1]&&v[i][0]>v[i][2])Max[0]++;
			if(v[i][1]>v[i][0]&&v[i][1]>v[i][2])Max[1]++;
			if(v[i][2]>v[i][0]&&v[i][2]>v[i][1])Max[2]++;
		}
		if(Max[0]>n/2||Max[1]>n/2||Max[2]>n/2)
		{
			if(Max[0]<=n/2)
			{
				if(Max[1]>n/2)
				{
					for(int i=1;i<=n;i++)swap(v[i][0],v[i][1]);
					swap(Max[0],Max[1]);
				}
				else 
				{
					for(int i=1;i<=n;i++)swap(v[i][0],v[i][2]);
					swap(Max[0],Max[2]);
				}
			}
			for(int i=1;i<=n;i++)
				if(v[i][0]>v[i][1]&&v[i][0]>v[i][2])q.push(max(v[i][1]-v[i][0],v[i][2]-v[i][0]));
			for(int i=1;i<=Max[0]-n/2;i++)ans+=q.top(),q.pop();
			while(!q.empty())q.pop();
		}
		cout<<ans<<'\n';
	}
}
