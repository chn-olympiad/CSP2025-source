#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;

int n;
int p[N][3];
vector<int> z[3];
ll ans;

void solve()
{
	cin>>n;
	ans=0;
	for(int i=0;i<3;i++) z[i].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i][0]>>p[i][1]>>p[i][2];
		int mx=-1,lmx=-1;
		for(int j=0;j<3;j++)
			if(mx==-1||p[i][j]>p[i][mx]) lmx=mx,mx=j;
			else if(lmx==-1||p[i][j]>p[i][lmx]) lmx=j;
		ans+=p[i][mx];
		z[mx].push_back(p[i][mx]-p[i][lmx]);
	}
	for(int i=0;i<3;i++)
		if(z[i].size()>n/2)
		{
			sort(z[i].begin(),z[i].end());
			int k=z[i].size(),now=0;
			while(k>n/2)
				ans-=z[i][now++],k--;
		}
	cout<<ans<<'\n';
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;cin>>_;
	while(_--) solve();
	return 0;
}

