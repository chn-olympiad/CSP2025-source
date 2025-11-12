#include<bits/stdc++.h>
using namespace std;
int read()
{
	int nw=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') nw=(nw<<3)+(nw<<1)+(ch-'0'),ch=getchar();
	return nw;
}
int n,m,k,len=0,leng=0,sumid[1030];
long long ans=1e18,sum=0,res[1030],val[12];
struct node{
	int a,b,c;
}E[1001000],S[20020],G[20020];
bool cmp(node a,node b) {return a.c<b.c;}
vector<node> mp[1030];
int fa[10101];
int d[12][100005];
int fd(int x)
{
	if(fa[x]!=x) return fa[x]=fd(fa[x]);
	return x;
}
void solve()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int xx=fd(E[i].a),yy=fd(E[i].b);
		if(xx==yy) continue;
		fa[xx]=yy;S[++len]=E[i];
		if(len==n-1) return ;
	}
	return ;
}
void solve2(int nw,int up,int m)
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	len=0;
	long long tmp=res[nw];
	for(int i=1;i<=m;i++)
	{
		int xx=fd(G[i].a),yy=fd(G[i].b);
		if(xx==yy) continue;
		fa[xx]=yy;S[++len]=G[i],tmp+=G[i].c;
		if(len==up-1||tmp>ans) return ;
	}
}
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) E[i].a=read(),E[i].b=read(),E[i].c=read();
	for(int i=1;i<=k;i++)
	{
		val[i]=read();
		for(int j=1;j<=n;j++) d[i][j]=read();	
	}
	stable_sort(E+1,E+m+1,cmp);
	solve();
	long long sum=0;
	for(int i=1;i<=len;i++) mp[0].push_back(S[i]),sum+=S[i].c;
	ans=min(ans,sum);
	len=0;
	for(int i=1;i<(1<<k);i++)
	{
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				int pre=i^(1<<(j-1));
				sumid[i]=sumid[pre]+1,res[i]=res[pre]+val[j];
				leng=0;
				for(auto i:mp[pre]) G[++leng]=i;
				for(int w=1;w<=n;w++) G[++leng]={n+j,w,d[j][w]};
				stable_sort(G+1,G+leng+1,cmp);
				solve2(i,sumid[i]+n,leng);
				long long temp=0;
				for(int kk=1;kk<=len;kk++) mp[i].emplace_back(S[kk]),temp+=S[kk].c;
				ans=min(ans,res[i]+temp);
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

//I'm the bone of the code
//Steel is my body,and fire is my blood
//I have writed over a thousand codes
//Unavare to loss,nor avare to gain
//Withstood pain to write many codes ,waiting for one's arrival.
//I have no regrets.This is the only path
//My whole life was "Unlimited Code Works".
//CSP-S2025 RP++ 