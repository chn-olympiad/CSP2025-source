#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+10;
int ans;
int a[N][5];
vector<int> c[4];
void solve()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=3;i++) c[i].clear();
	for(int i=1;i<=n;i++)
	{
		int num=0;a[i][0]=-1;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[i][num]) num=j;
		}
		sort(a[i]+1,a[i]+4);
		c[num].push_back(a[i][3]-a[i][2]);
		ans+=a[i][3];
	}
	for(int i=1;i<=3;i++)
	{
		if(c[i].size()>n/2)
		{
			sort(c[i].begin(),c[i].end());
			int p=c[i].size()-n/2;
			for(int j=0;j<p;j++) ans-=c[i][j];
		}
	}
	cout<<ans<<'\n';	
}
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
