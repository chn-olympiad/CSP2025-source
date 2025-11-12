#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans;
vector<int> vec[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=0;
			if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) mx=1;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]) mx=2;
			ans+=a[i][mx];
			int p1=(mx+1)%3,p2=(p1+1)%3;
			vec[mx].emplace_back(a[i][mx]-max(a[i][p1],a[i][p2]));
		}
		for(int i=0;i<3;i++)
		{
			sort(vec[i].begin(),vec[i].end());
			for(int j=0;j+n/2<vec[i].size();j++) ans-=vec[i][j];
			vec[i].clear();
		}
		cout<<ans<<"\n";
		ans=0;
	}
}