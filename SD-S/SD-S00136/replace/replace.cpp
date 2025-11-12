#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,q,s[200050];
long long ans;
string c[200050][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i][0];
		cin>>c[i][1];
		s[i]=int(c[i][0].size());
	}
	while(q--)
	{
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int t=int(t1.size());
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=t-s[i];j++)
			{
				int f=1;
				for(int k=0;k<s[i];k++)
				{
					if(t1[k+j]!=c[i][0][k])
					{
						f=0;
						break;
					}
				}
				if(!f) continue;
				for(int k=0;k<t;k++)
				{
					if(k>=j&&k<j+s[i])
					{
						if(t2[k]!=c[i][1][k-j])
						{
							f=0;
							break;
						}
					}
					else
					{
						if(t1[k]!=t2[k])
						{
							f=0;
							break;
						}
					}
				}
				ans+=f;
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

*/
