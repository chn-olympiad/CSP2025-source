#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,i,k,o;
string s1[200001],s2,t1,t2,p,tt1,tt2;
map<string,int> m1;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2;
		if(s1[i]==s2)
		{
			continue;
		}
		m1[s1[i]+"-"+s2]++;
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		o=0;
		for(i=1;i<=n;i++)
		{
			k=t1.find(s1[i]);
			if(k==-1)
			{
				continue;
			}
			p=t2;
			p.erase(0,k);
			p.erase(s1[i].size());
			tt1=t1;
			tt2=t2;
			tt1.erase(k,s1[i].size());
			tt2.erase(k,s1[i].size());
			if(tt1==tt2)
			{
				o+=m1[s1[i]+"-"+p];
			}
		}
		cout<<o<<"\n";
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
