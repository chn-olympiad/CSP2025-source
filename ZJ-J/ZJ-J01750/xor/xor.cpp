#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int n,m,t,k,a[N],s[N];
vector<int> mp[N];
bool cmp1(pair<int,int> _1,pair<int,int> _2)
{
	return _1.first<_2.first;
}
bool cmp2(pair<int,int> _1,pair<int,int> _2)
{
	return _1.second<_2.second;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<pair<int,int> >v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			v.push_back({i,i});
			//cout<<"yet\n";
			//cout<<"tiao"<<i<<' '<<i<<"\n";
		}
		s[i]=s[i-1]^a[i];
		mp[s[i]].push_back(i);
	}
	
	for(int i=1;i<=n;i++)
	{
		int fund=s[i-1]^k;
		int close=-1;
		for(int j=0;j<mp[fund].size();j++)
		{
			if((abs(mp[fund][j]-i)<=abs(close-i)&&i!=mp[fund][j]||close==-1&&i!=mp[fund][j])&&mp[fund][j]>i) close=mp[fund][j];
			if((abs(mp[fund][j]-i)>=abs(close-i)&&close!=-1)) break;
		}
		if(close!=-1)v.push_back({min(i,close),max(i,close)});
		//cout<<"tiao"<<min(i,close)<<" "<<max(i,close)<<"\n";
	}
	int last=0,cc=0;
	stable_sort(v.begin(),v.end(),cmp1);
	stable_sort(v.begin(),v.end(),cmp2);
	for(int i=0;i<v.size();i++)
	{
		if(v[i].first>last)
		{
			cc++;
			last=v[i].second;
		}
	}
	cout<<cc;
}
//4 0 2 1 0 3
