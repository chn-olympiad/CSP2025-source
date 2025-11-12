#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	vector<int> v;
	for(int i=0,l=s.size();i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v.push_back(int(s[i]-'0'));
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	string k="";
	for(int i=0,l=v.size();i<l;i++)
	{
		k+=char(v[i]+'0');
	}
	cout<<k;
	return 0;
}