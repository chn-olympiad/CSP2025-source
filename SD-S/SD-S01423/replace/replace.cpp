#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 200005
#define M 5000006
using namespace std;
int read()
{
	int fl=1,x=0;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')fl=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*fl;
}
int Ka=31,Kb=331;
struct HV{
	ull Hasha,Hashb;
	bool operator==(HV const&a)const
	{
		return Hasha==a.Hasha&&Hashb==a.Hashb;
	}
};
struct po{
	int la,lb,lc,id;
	HV A,B,C,D;
}num[N],q[N];
char s[M],t[M];
int n,m,ans[N];
HV vs[M],vt[M],p[M];
void gethash()
{
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		vs[i].Hasha=vs[i-1].Hasha*Ka+s[i]-'a';
		vs[i].Hashb=vs[i-1].Hashb*Kb+s[i]-'a';
	}
	for(int i=1;i<=len;i++)
	{
		vt[i].Hasha=vt[i-1].Hasha*Ka+t[i]-'a';
		vt[i].Hashb=vt[i-1].Hashb*Kb+t[i]-'a';
	}
}
HV query(int l,int r,int x)
{
	if(l>r)return HV{0,0};
	if(x==0)return HV{vs[r].Hasha-vs[l-1].Hasha*p[r-l+1].Hasha,vs[r].Hashb-vs[l-1].Hashb*p[r-l+1].Hashb};
	else return HV{vt[r].Hasha-vt[l-1].Hasha*p[r-l+1].Hasha,vt[r].Hashb-vt[l-1].Hashb*p[r-l+1].Hashb};
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=HV{1,1};
	for(int i=1;i<=5e6;i++)
	{
		p[i].Hasha=p[i-1].Hasha*Ka;
		p[i].Hashb=p[i-1].Hashb*Kb;
	}
	n=read();m=read();
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s+1,t+1);
		int len=strlen(s+1);
		int x=1,y=len;
		while(s[x]==t[x]&&x<=len)x++;
		while(s[y]==t[y]&&y)y--;
		if(x==len+1)continue;
		cnt++;
		num[cnt].id=cnt;
		num[cnt].la=x-1;
		num[cnt].lb=y-x+1;
		num[cnt].lc=len-y;
		gethash();
		num[cnt].A=query(1,x-1,0);
		num[cnt].D=query(y+1,len,0);
		num[cnt].B=query(x,y,0);
		num[cnt].C=query(x,y,1);
	}
	n=cnt;
	for(int i=1;i<=m;i++)
	{
		scanf("%s%s",s+1,t+1);
		int len=strlen(s+1);
		int x=1,y=len;
		while(s[x]==t[x]&&x<=len)x++;
		while(s[y]==t[y]&&y)y--;
		gethash();
		int Ans=0;
		q[i].la=x-1;
		q[i].lc=len-y;
		q[i].lb=y-x+1;
		q[i].B=query(x,y,0);
		q[i].C=query(x,y,1);
		for(int j=1;j<=n;j++)
		{
			if(q[i].B==num[j].B&&q[i].C==num[j].C&&q[i].lb==num[j].lb)
			{
				if(q[i].la<num[j].la)continue;
				if(q[i].lc<num[j].lc)continue;
				if(query(x-num[j].la,x-1,0)==num[j].A&&query(y+1,y+num[j].lc,0)==num[j].D)
					Ans++;
			}
		}
		cout<<Ans<<'\n';
	}
	return 0;
}
