#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
map<string,string> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
	}
	while(q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(mp.count(t1))	ans++;
		cout<<ans<<'\n'; 
	}
}