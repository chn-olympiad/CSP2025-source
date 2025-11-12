#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >v[10005];
unordered_map<int,int>mp;
int n,m,k,in[10005],s=0,a[1000005],t=0;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y>>a[i];
		in[x]++;
		in[y]++;
		v[x].push_back({y,a[i]});
		v[y].push_back({x,a[i]});
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==1)
		{
			s+=v[i][0].second;
			t++;
			mp[v[i][0].second]++;
			v[i].pop_back();
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(mp[a[i]])
		{
			mp[a[i]]--;
			continue;
		}
		s+=a[i];
		t++;
		if(t==n-1) break;
	}
	cout<<s<<endl;
	return 0;
}
