#include <bits/stdc++.h>
using namespace std;
long long n,q,ans;
string s[200010][14];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>s[i][3]>>s[i][4];
		for(int k=1;k<=n;k++)
		{
			for(int j=0;j<s[i][3].length()-s[k][1].length()+1;j++)
   			{
				string s2=s[i][3];
				s2.erase(j,s[k][1].length());
				s2.insert(j,s[k][2]);
				if(s2==s[i][4])
				{
					s2.erase(j,s[k][2].length());
					s2.insert(j,s[k][1]);
					if(s2==s[i][3])
					{
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}