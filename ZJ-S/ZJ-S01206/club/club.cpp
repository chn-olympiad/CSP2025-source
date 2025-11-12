#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second
#define endl '\n'
#define start_multitest\
	int tests;\
	cin>>tests;\
	for(int test_case=1;test_case<=tests;test_case++)[&]()->int\
	{
#define end_multitest\
		return 0;\
	}();
constexpr int N=100010;
int n;
ll ans;
array<int,3>A[N];
int C[N];
int cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	start_multitest
	ans=0;
	fill(cnt,cnt+3,0);
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>A[i][j];
	for(int i=1;i<=n;i++)
	{
		const auto &x=A[i];
		int m=max({x[0],x[1],x[2]});
		for(int j=0;j<3;j++)
			if(m==x[j])
			{
				cnt[j]++;
				C[i]=j;
				ans+=m;
				break;
			}
	}
	if(cnt[0]<=n>>1&&cnt[1]<=n>>1&&cnt[2]<=n>>1)return cout<<ans<<endl,0;
	int f;
	if(cnt[0]>n>>1)f=0;
	else if(cnt[1]>n>>1)f=1;
	else f=2;
	vector<pair<int,int>>V;
	for(int i=1;i<=n;i++)
		if(C[i]==f)
		{
			int m=INT_MAX;
			for(int j=0;j<3;j++)if(j!=f)m=min(m,A[i][f]-A[i][j]);
			V.push_back({i,m});
		}
	sort(V.begin(),V.end(),[&](const auto &x,const auto &y)->bool
	{
		return x.se<y.se;
	});
	for(int i=0;i<cnt[f]-(n>>1);i++)ans-=V[i].se;
	cout<<ans<<endl;
	end_multitest
	return 0;
}