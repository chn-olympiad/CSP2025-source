/*
董国栋
SN-00623
西安市曲江第一学校 
*/
#include<bits/stdc++.h>
using namespace std;
string s[200010][2],t[2];
int n,q;
int main()
{
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		int ans=0;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size())
		{
			cout<<"0\n";
			continue;
		}
		int l,r;
		for(l=0;t[0][l]==t[1][l];l++);
		for(r=t[0].size()-1;t[0][r]==t[1][r];r--);
		for(int i=1;i<=n;i++)
		{
			if(s[i][0].size()<r-l+1||s[i][0].size()>t[0].size())
				continue;
			for(int j=max(0,r-(int)t[0].size()+1);j<=min(l,(int)t[0].size()-(int)s[j][0].size()+1);j++)
			{
				for(int k=j;k<=j+s[i][0].size()-1;k++)
				{
					if(t[0][k]!=s[i][0][k]||t[1][k]!=s[i][1][k])
						goto there;
				}
				ans++;
				there:;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}



















