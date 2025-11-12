#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,int> s;
string a[10005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		int b=-1,l=-1;
		cin>>a[i][0];
		cin>>a[i][1];
		for(int j=0;j<a[i][0].size();j++)
		{
			if(a[i][0][j]!=a[i][1][j])
			{
				l=j;
				if(b==-1)b=j;
			}
		}
		s[{a[i][0].substr(b,l-b+1),a[i][1].substr(b,l-b+1)}]++;
	}
	string l1,l2;
	while(q--)
	{
		int b=-1,l=-1;
		cin>>l1>>l2;
		for(int j=0;j<l1.size();j++)
		{
			if(l1[j]!=l2[j])
			{
				l=j;
				if(b==-1)b=j;
			}
		}
		cout<<s[{l1.substr(b,l-b+1),l2.substr(b,l-b+1)}]<<'\n';
	}
	return 0;
}
