//SN-J01084 menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
string s;
map<int,int>mp;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			mp[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(mp[i]--)
			cout<<i;
	return 0;
}
