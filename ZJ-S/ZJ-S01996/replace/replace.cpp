#include<bits/stdc++.h>
using namespace std;
string s[2][200001],t1,t2,tt;
int n,q,l,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i];
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=t2.size();k++)
			{
				tt=t1,l=0;
				for(;l<s[0][j].size();l++)
				{
					if(tt[k+l]!=s[0][j][l]) break;
					tt[k+l]=s[1][j][l];
				}
				if(l==s[0][j].size()&&tt==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

