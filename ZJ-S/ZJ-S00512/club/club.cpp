#include<bits/stdc++.h>
using namespace std;
vector<int> v[3];
void solve()
{
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a>=b&&a>=c)
		{
			v[0].push_back(a-(b+c-min(b,c)));
			cnt+=a;
		}
		else if(b>=a&&b>=c)
		{
			v[1].push_back(b-(a+c-min(a,c)));
			cnt+=b;
		}
		else
		{
			v[2].push_back(c-(a+b-min(a,b)));
			cnt+=c;
		}
	}
	
	for(int i=0;i<=2;i++)
	{
		sort(v[i].begin(),v[i].end());
		int k=v[i].size();
		for(int j=1;j<=k-n/2;j++) cnt-=v[i][j-1];
		v[i].clear();
	}
	cout<<cnt<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
