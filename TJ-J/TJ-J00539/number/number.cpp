#include<bits/stdc++.h>
using namespace std;
string s;
map <char,int> mp;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		mp[s[i]]++;
	}
	for(char i='9';i>='0';i--)
	{
		if(mp[i]!=0)
		{
			while(mp[i]--)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
