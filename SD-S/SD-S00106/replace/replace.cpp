#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n,q,ans;

string s[N][3];


void compare(string a,string b,int x)
{
	for(int i=0;i<a.size();i++)
		if(a.substr(i,s[x][1].size())==s[x][1])
			if(a.substr(0,i)+s[x][2]+a.substr(s[x][2].size()+i,a.size()-s[x][2].size())==b)
				ans++;
				
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		ans=0;
		for(int i=1;i<=n;i++)
			compare(a,b,i);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
