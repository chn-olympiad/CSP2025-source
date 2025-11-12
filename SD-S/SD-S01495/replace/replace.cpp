#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=1e4+7;
string s[N][5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		s[i][1]=' '+s[i][1];
		s[i][2]=' '+s[i][2];
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		s1=' '+s1;
		s2=' '+s2;
		int ls,rs;
		for(int i=1;i<s1.size();i++)
			if(s1[i]!=s2[i])
			{
				ls=i;
				break;
			}
		for(int i=s1.size()-1;i>=1;i--)
			if(s1[i]!=s2[i])
			{
				rs=i;
				break;
			}
		int ln=rs-ls+1;
		int ans=0;
		for(int l=1;l<=ls;l++)
		{
			for(int len=rs-l+1;len<s1.size() && l+len-1>=rs && l+len-1<s1.size();len++)
			{
				int r=l+len-1;
				for(int i=1;i<=n;i++)
				{
					if(s[i][1].size()-1!=len) continue;
					bool flag=1;
					for(int j=1;j<s[i][1].size();j++)
						if(s[i][1][j]!=s1[l+j-1])
						{
							flag=0;
							break;
						}
					if(flag==0) continue;
					for(int j=1;j<s[i][2].size();j++)
						if(s[i][2][j]!=s2[l+j-1])
						{
							flag=0;
							break;
						}
					if(flag) ans++;
				}
			}
		}
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
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
