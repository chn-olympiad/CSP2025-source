#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,q,le,ri;
string s1[N],s2[N],t1,t2;
void ock()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
signed main()
{
	ock();
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>t1>>t2;
		le=0x3f3f3f3f;
		ri=0;
		for(int l=0;l<t1.size();l++)
		{
			if(t1[l]!=t2[l])
			{
				le=min(le,l);
				ri=max(ri,l);
			}
		}
		for(int l=0;l<=le;l++)
		{
			for(int j=1;j<=n;j++)
			{
				if(t1.size()-l>=s1[j].size()&&l+s1[j].size()-1>=ri)
				{
					int flag=1;
					for(int k=0;k<s1[j].size();k++)
					{
						if(s1[j][k]!=t1[l+k])
						{
							flag=0;
							break;
						}
					}
					if(flag==1)
					{
						int flag2=1;
						for(int k=0;k<s2[j].size();k++)
						{
							if(s2[j][k]!=t2[l+k])
							{
								flag2=0;
								break;
							}
						}
						if(flag2==1)
						{
							ans++;
							//cout<<s1[j]<<" "<<s2[j]<<" "<<l<<"\n";
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
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
