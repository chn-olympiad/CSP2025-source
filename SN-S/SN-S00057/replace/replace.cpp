#include<bits/stdc++.h>
const int MAXN=(2e5+5);
int n,q;
std::string a[MAXN],b[MAXN];
bool suf[MAXN],pre[MAXN];
std::map<std::string,std::map<std::string,bool> > vis;
inline void solve()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		std::cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		vis[a[i]][b[i]]++;
	while(q--)
	{
		std::string t1,t2;
		std::cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			printf("0\n");
			continue;
		}
		int len=t1.size();
		suf[0]=(t1[0]==t2[0]);
		for(int i=1;i<len;i++)
			suf[i]=(suf[i-1]&(t1[i]==t2[i]));
		pre[len]=1;
		for(int i=len-1;i>=0;i--)
			pre[i]=(pre[i+1]&(t1[i]==t2[i]));
		int ans=vis[t1][t2];
		for(int i=0;i<=len;i++)
		{
			if(!suf[i])
				continue;
			std::string s="",l="";
			for(int j=i;j<len;j++)
			{
				s+=t2[j],l+=t1[i];
				if(pre[j]) ans+=vis[l][s];
			}
		}
		for(int i=0;i<len;i++)
		{
			if(!suf[i])
				continue;
			std::string s="",l="";
			for(int j=i;j<len;j++)
			{
				s+=t2[j],l+=t1[j];
				ans+=vis[l][s];
			}
		}
		int w=-1;
		for(int i=len-1;i>=0;i--)
		{
			if(!pre[i])
				break;
			std::string s="",l="";
			for(int j=i;j>=0;j--)
			{
				s+=t2[j],l+=t1[j];
				ans+=vis[l][s];
			}
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}
