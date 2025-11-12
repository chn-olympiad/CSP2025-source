#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+105;
int n,m;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	string ss1,ss2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(m--)
	{
		ll ans=0;
		cin>>ss1>>ss2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<ss1.size();j++)
			{
				string s3="";
				for(int k=j;k<j+s1[i].size();k++)
				{
					s3+=ss1[i];
				}
				if(s3==s1[i])
				{
					string s4="";
					for(int k=1;k<ss1.size();k++)
					{
						if(j<=k&&k<j+s1[i].size())
						{
							s4+=s3[k];
						}
						else  s4+=ss1[k];
					}
					if(s4==ss2) ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
