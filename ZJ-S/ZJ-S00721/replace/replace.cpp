#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
map<string,string>f;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		f[s1]=s2;
	}
	while(q--)
	{
		string x1,x2;
		cin>>x1>>x2;
		int len=x1.size();
		int ans=0;
		for(int i=0;i<len;i++)
		{
			string sx="";
			for(int j=i;j<len;j++)
			{
				sx+=x1[j];
				if(f[sx]!="")
				{
					string x="";
					for(int k1=0;k1<i;k1++)
						x+=x1[k1];
					x+=f[sx];
					for(int k1=j+1;k1<len;k1++)
						x+=x1[k1];
					if(x==x2)
						ans++;
				}
			}
		}
		cout<<ans<<"\n";
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

3 4 
a b
b c
c d
aa bb
aa b
a c
b a
*/
