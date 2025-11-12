// 许景焱 SN-S00654 西安铁一中滨河高级中学
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn=100000;

int n,ans,s1,s2,s3;
int a[maxn+5][5];
vector<int>c[5];

bool cmp(int i,int j)
{
	if(a[i][0]-a[i][4]==a[j][0]-a[j][4])
		return i<j;
	return a[i][0]-a[i][4]<a[j][0]-a[j][4];
}

signed main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		c[1].clear();
		c[2].clear();
		c[3].clear();
		cin>>n;
		ans=0;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][0]=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=a[i][0];
			if(a[i][1]==a[i][0])
			{
				a[i][4]=max(a[i][2],a[i][3]);
				c[1].push_back(i);
			}
			else if(a[i][2]==a[i][0])
			{
				a[i][4]=max(a[i][1],a[i][3]);
				c[2].push_back(i);
			}
			else if(a[i][3]==a[i][0])
			{
				a[i][4]=max(a[i][1],a[i][2]);
				c[3].push_back(i);
			}
		}
		if(c[1].size()>n/2)
		{
			sort(c[1].begin(),c[1].end(),cmp);
			for(int i=c[1].size(); i>n/2; i--)
			{
				ans-=a[c[1][c[1].size()-i]][0];
				ans+=a[c[1][c[1].size()-i]][4];
			}
		}
		if(c[2].size()>n/2)
		{
			sort(c[2].begin(),c[2].end(),cmp);
			for(int i=c[2].size(); i>n/2; i--)
			{
				ans-=a[c[2][c[2].size()-i]][0];
				ans+=a[c[2][c[2].size()-i]][4];
			}
		}
		if(c[3].size()>n/2)
		{
			sort(c[3].begin(),c[3].end(),cmp);
			for(int i=c[3].size(); i>n/2; i--)
			{
				ans-=a[c[3][c[3].size()-i]][0];
				ans+=a[c[3][c[3].size()-i]][4];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
