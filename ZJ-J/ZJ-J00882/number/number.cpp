#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	map<char,int>mp;
	for(char it:s)mp[it]++;
	string ans="";
	for(auto it:mp)
	{
		if(it.first>='0' && it.first<='9')for(int i=1;i<=it.second;i++)ans+=it.first;
	}
	for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
	return 0;
}

