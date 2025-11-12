#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
const int N=500+10,mod=998244353;
int n,m;
string s;
int c[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==m)
	{
		for(int i=0;i<n;i++)
			if(s[i]!='1')
				return cout<<0<<endl,0;
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		return cout<<ans<<endl,0;
	}
	if(n>18)
		return cout<<0<<endl,0;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	vector<int> id;
	for(int i=1;i<=n;i++)
		id.emplace_back(i);
	int ans=0;
	do{
		int cnt=0,res=0;
		for(int i=0;i<n;i++)
		{
			if(cnt>=c[id[i]])
			{
				cnt++;
				continue;
			}
			if(s[i]=='1')
				res++;
			else
				cnt++;
		}
		if(res>=m)
			ans++;
	}while(next_permutation(id.begin(),id.end()));
	cout<<ans<<endl;
	return 0;
}