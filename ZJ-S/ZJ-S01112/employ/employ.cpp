#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int N=200005;
const int mod=998244353;

int n,m,a[N];

string s;

map<int,int> mp;

int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	
//  luogu : Pyrf_uqcat
//  uid : 1137860	
//  %%% _Deer_Peach_ orz
	
//	00:45 T1 : 100 pts
//	01:28 T3 : 25 pts
//	02:24 T2 : 16 pts	
//  03:48 T4 : 4 pts
//  Sad Ending.

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') a[0]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	if(a[0]) cout<<0<<endl;
	else
	{
		sort(a+1,a+n+1);
		ll res=1;
		ll cnt=upper_bound(a+1,a+n+1,m)-a;
		cnt=n-cnt+1;
		for(int i=n;i>=1;i--)
		{
			cnt+=mp[i];
			res=(res*cnt--)%mod;
		}
		cout<<res<<endl;
	}
	return 0;
}
