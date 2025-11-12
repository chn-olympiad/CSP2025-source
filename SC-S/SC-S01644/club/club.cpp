#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100006][3],H[16];
struct P{
	int d,i;
};
bool operator<(P a,P b)
{
	return a.d<b.d;
}
void solve()
{
	cin>>n;
	for(int j=0;j<3;j++)H[j]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)cin>>a[i][j];
	}
	vector<int> delta[3];
	int ans=0;//
	for(int i=0;i<n;i++)
	{
		vector<P> V;
		for(int j=0;j<3;j++)V.push_back(P{a[i][j],j});
		sort(V.begin(),V.end());
		H[V[2].i]++;
		ans+=V[2].d;
		delta[V[2].i].push_back(V[2].d-V[1].d);
	}
	for(int j=0;j<3;j++)
	{
		if(H[j]>n/2)
		{
			sort(delta[j].begin(),delta[j].end());
			int p=0;
			while(H[j]>n/2)
			{
				ans-=delta[j][p];
				p++;
				H[j]--;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}