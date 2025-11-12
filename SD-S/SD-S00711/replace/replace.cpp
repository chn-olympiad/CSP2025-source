#include<bits/stdc++.h> 
using namespace std;
int n,q;
string s[10010][2],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(t1.find(s[j][0])==t2.find(s[j][1]))
			{
				bool m=1;
				for(int k=0;k<t1.find(s[j][0]);k++)
				{
					if(t1[k]!=t2[k])
					{
						m=0;
						break;
					}
				}
				for(int k=t1.find(s[j][0])+s[j][0].length();k<t1.length();k++)
				{
					if(t1[k]!=t2[k])
					{
						m=0;
						break;
					}
				}
				if(m) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
