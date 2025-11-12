#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,se,ss,s1[1005],s2[1005];
int ans,q,n,f;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		ans=0;
		cin>>s>>se;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s.size();j++)
			{
				f=1;
				if(s1[i].size()>s.size()-j)	break;
				for(int k=0;k<s1[i].size();k++)
				{
					if(s1[i][k]!=s[j+k]){
						f=0;
						break;
					}
				}
				ss=s;
				if(f)
				{
					for(int k=0;k<s1[i].size();k++)
					{
						ss[j+k]=s2[i][k];
					}
				}
				if(ss==se)	ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}