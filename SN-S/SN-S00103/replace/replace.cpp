#include<bits/stdc++.h>
using namespace std;
string s[200010][3],t[200010][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	if(q==1)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<t[1][1].size();j++)
			{
				if(t[1][1][j]==s[i][1][0]&&t[1][1][j+s[i][1].size()-1]==s[i][1][s[i][1].size()-1]&&t[1][2][j]==s[i][2][0]&&t[1][2][j+s[i][2].size()-1]==s[i][2][s[i][2].size()-1])
				{
					bool u=1;
					for(int k=j;k<=j+s[i][1].size()-1;k++)
					{
						if(t[1][1][k]!=s[i][1][k-j]||t[1][2][k]!=s[i][2][k-j])
						{
							cout<<k;
							u=0;
						}
					}
					if(u)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}//放弃就是失败，骗分就是胜利 
