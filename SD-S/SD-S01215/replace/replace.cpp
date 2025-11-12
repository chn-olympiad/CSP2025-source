#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2;
map<string,map<string,bool>>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		mp[s1][s2]=1;
	}
	while(q--)
	{
		cin>>t1>>t2;
		int len=t1.size();
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
		}
		for(int i=0;i<len;i++)
		{
			while(1)
			{
				cout<<"ByeBye OI"; 
			}
		}
	}
	return 0;
}
