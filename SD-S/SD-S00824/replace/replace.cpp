#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+100;
int n,m;
string s[N][2],t[N][2];
LL bs=1145141,mod=1e9+7,pre1[N],pre2[N],suf1[N],suf2[N];
map<LL,map<LL,int> >mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i][0]>>s[i][1];
		LL suma=0,sumb=0;
		for(int j=0;j<s[i][0].size();j++)
		{
			suma=(suma*bs+s[i][0][j]-'a'+1)%mod;
		}
		for(int j=0;j<s[i][1].size();j++)
		{
			sumb=(sumb*bs+s[i][1][j]-'a'+1)%mod;
		}
		mp[suma][sumb]++;
	}
	for(int i=1;i<=m;i++) 
	{
		LL ans=0;
		cin>>t[i][0]>>t[i][1];
		int len1=t[i][0].size(),len2=t[i][1].size();
		if(len1==len2)
		{
			pre1[0]=pre2[0]=suf1[len1+1]=suf2[len1+1]=0;
			for(int j=1;j<=len1;j++)
			{
				pre1[j]=(pre1[j-1]*bs+t[i][0][j-1]-'a'+1)%mod;
				pre2[j]=(pre2[j-1]*bs+t[i][1][j-1]-'a'+1)%mod;
			}
			for(int j=len1;j>=1;j--)
			{
				suf1[j]=(suf1[j+1]*bs+t[i][0][j-1]-'a'+1)%mod;
				suf2[j]=(suf2[j+1]*bs+t[i][1][j-1]-'a'+1)%mod;
			}
			for(int j=1;j<=len1;j++)
			{
				LL suma=0,sumb=0;
				for(int k=j;k<=len1;k++)
				{
					suma=(suma*bs+t[i][0][k-1]-'a'+1)%mod;
					sumb=(sumb*bs+t[i][1][k-1]-'a'+1)%mod;
					if(pre1[j-1]==pre2[j-1]&&suf1[k+1]==suf2[k+1])
					{
						ans+=mp[suma][sumb];
					}
				}
			}
			printf("%lld\n",ans);
		}
		else printf("0\n");
	}
	
	
	return 0;
}

