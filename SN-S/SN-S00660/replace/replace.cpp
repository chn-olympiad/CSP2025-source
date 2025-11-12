#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s1[MAXN],s2[MAXN];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string t1,t2; cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+s1[i].size()<=t1.size();j++)
			{
				if(t1.substr(j,s1[i].size())!=s1[i]) continue;
				string now=t1.substr(0,j);
				now+=s2[i];
				now+=t1.substr(j+s1[i].size(),t1.size()-(j+s1[i].size()-1)-1);
//				cout<<j<<endl;
//				cout<<now<<endl;
				
				ans+=(now==t2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1 1
a b
absv bbsv

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
