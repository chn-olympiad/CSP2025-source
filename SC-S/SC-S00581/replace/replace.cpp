#include<bits/stdc++.h>
using namespace std;
int n,q,ans,b[5000010],cnt[5000010],len[5000010],ch[5000010][30],tmp=1,nxt[5000010],v[5000010];
string s1,s2;
queue<int>que;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d\n",&n,&q);
	for(int i=1;i<=n;++i)
	{
		char x=getchar();
		int p=0,l=0;
		while(x!=' ')
		{
			if(!ch[p][x-'a'])
				ch[p][x-'a']=++tmp;
			p=ch[p][x-'a'];
			len[p]=++l;
			x=getchar();
		}
		++cnt[p];
		if(!b[p])
			b[p]=i;
		p=1;
		x=getchar();
		while(x!='\n')
		{
			if(!ch[p][x-'a'])
				ch[p][x-'a']=++tmp;
			p=ch[p][x-'a'];
			x=getchar();
		}
		if(!b[p])
			b[p]=i;
	}
	for(int i=0;i<26;++i)
	{
		if(ch[0][i])
			que.push(ch[0][i]);
		if(ch[1][i])
			que.push(ch[1][i]);
		else
			ch[1][i]=1;
		nxt[ch[1][i]]=1;
	}
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		for(int i=0;i<26;++i)
			if(ch[u][i]&&ch[u][i]!=1)
				nxt[ch[u][i]]=ch[nxt[u]][i],que.push(ch[u][i]);
			else
				ch[u][i]=ch[nxt[u]][i];
	}
	for(int i=1;i<=q;++i)
	{
		cin>>s1>>s2;
		ans=0;
		int l=1e9,r;
		for(int j=0,st=s1.size();j<st;++j)
			if(s1[j]!=s2[j])
				l=min(l,j),r=j;
		for(int j=0,st=s1.size(),p1=0,p2=1;j<st;++j)
		{
			p1=ch[p1][s1[j]-'a'];
			p2=ch[p2][s2[j]-'a'];
			if(j>=r)
			{
				for(int k1=p1,k2=p2;j-len[k1]<l&&b[k1]==b[k2]&&v[k1]!=i;k1=nxt[k1],k2=nxt[k2])
					v[k1]=i,ans+=cnt[k1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}