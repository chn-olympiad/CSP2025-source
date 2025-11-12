#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v[3];
int a[100005][3],n;
const int inf=0x3f3f3f3f3f3f3f3f;
void test()
{
	v[0].clear(),v[1].clear(),v[2].clear();
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int mx=0,mt=0;
		for(int j=0;j<=2;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>mx)
				mx=a[i][j],mt=j;
		}
		int mn=inf;
		for(int j=0;j<=2;j++)
			if(j!=mt)
				mn=min(mn,mx-a[i][j]);
		v[mt].push_back(mn);
		ans+=mx;
	}
	int m=n>>1;
	for(int i=0;i<=2;i++)
	{
		sort(v[i].begin(),v[i].end(),greater<int>());
		for(int j=m;j<v[i].size();j++)
			ans-=v[i][j];
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		test();
}
//end at 14:42