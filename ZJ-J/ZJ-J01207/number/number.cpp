#include<bits/stdc++.h>
using namespace std;
vector<char> v;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end());
	if(v[v.size()-1]=='0')
	{
		cout<<0;
		return 0;
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i];
	}
	return 0;
}
