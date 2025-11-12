#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N=1e5+5;

int T,n,s1,s2,s3,ans;
int a[N][5];
priority_queue<int,vector<int>,greater<int> > q[5];

void clear()
{
	s1=s2=s3=0;
	ans=0;
	while(!q[1].empty())
		q[1].pop();
	while(!q[2].empty())
		q[2].pop();
	while(!q[3].empty())
		q[3].pop();
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			int t=max(a[i][1],max(a[i][2],a[i][3]));
			if(t==a[i][1])
			{
				s1++;
				ans+=t;
				q[1].push(t-max(a[i][2],a[i][3]));
			}
			else if(t==a[i][2])
			{
				s2++;
				ans+=t;
				q[2].push(t-max(a[i][1],a[i][3]));
			}
			else if(t==a[i][3])
			{
				s3++;
				ans+=t;
				q[3].push(t-max(a[i][1],a[i][2]));
			}
		}
		while(s1>(n/2))
		{
			s1--;
			ans-=q[1].top();
			q[1].pop();
		}
		while(s2>(n/2))
		{
			s2--;
			ans-=q[2].top();
			q[2].pop();
		}
		while(s3>(n/2))
		{
			s3--;
			ans-=q[3].top();
			q[3].pop();
		}
		cout<<ans<<endl;
		clear();
	}
	return 0;
}
