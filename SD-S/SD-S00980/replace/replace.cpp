#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5,maxs=5e6;
int b[maxs+10],c[maxs+10],cnt[maxs+10];
int fth[maxs+10],len[maxs+10];
int ans,lt,rt,lens,sa,n,p,q,tot=1,x;
int ch[maxs+10];
char s[maxs+10],t[maxs+10];
map<int,int>mp[maxs+10];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%s%s",s,t);
		lens=strlen(s);
		p=1;
		for(j=0;j<=lens-1;++j)
		{
			sa=(s[j]-'a')*26+(t[j]-'a')+1;
			if(!mp[p][sa])
			{
				mp[p][sa]=++tot;
				fth[tot]=p;
				ch[tot]=sa;
				len[tot]=len[p]+1;
			}
			p=mp[p][sa];
		}
		++cnt[p];
	}
	b[1]=0;
	for(i=2;i<=tot;++i)
	{
		p=b[fth[i]];
		while(p>=2&&!mp[p][ch[i]])
			p=b[p];
		if(mp[p][ch[i]])
			b[i]=mp[p][ch[i]];
		else b[i]=1;
	}
	b[1]=1;
	while(q--)
	{
		scanf("%s%s",s,t);
		lens=strlen(s);
		if(lens!=strlen(t))
		{
			puts("0");
			continue;
		}
		p=1;
		ans=0;
		lt=lens;
		rt=0;
		for(i=0;i<=lens-1;++i)
		{
			if(s[i]!=t[i])
			{
				lt=min(lt,i);
				rt=max(rt,i);
			}
		}
		for(i=0;i<=lens-1;++i)
		{
			sa=(s[i]-'a')*26+(t[i]-'a')+1;
			if(i>=1)
				x=c[i-1];
			else x=1;
			while(x>=2&&!mp[x][sa])
				x=b[x];
			if(mp[x][sa])
				c[i]=mp[x][sa];
			else c[i]=1;
			x=c[i];
			do
			{
				if(i>=rt&&i-len[x]+1<=lt)
					ans+=cnt[x];
				else break;
				x=b[x];
			}while(x>=2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
