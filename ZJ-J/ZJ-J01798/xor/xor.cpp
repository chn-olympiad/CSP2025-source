#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
const int INF=0x3f3f3f3f;
int n,k,ans,cnt;
int a[N];
vector<pair<int,int>> s;
priority_queue<int> q;
inline void fre()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int ans=a[i];
		if(ans==k) 
		{
			s.push_back({i,i});
			continue;
		}
		for(int j=i+1;j<=n;j++) 
		{
			ans^=a[j];
			if(ans==k) 
			{
				s.push_back({i,j});
				break;
			}
		}
	}
	sort(s.begin(),s.end());
	for(auto v:s) 
		if(q.empty()||v.first>q.top())
		{
			q.push(v.second);
			cnt++;	
		}
	cout<<cnt<<'\n';
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/