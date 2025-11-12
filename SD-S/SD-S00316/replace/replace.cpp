#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=5e6+10;
inline int readstr(string &s)
{
	s=" ";char ch=getchar();int r=0;
	while(ch<'a'||ch>'z') ch=getchar();
	while(ch>='a'&&ch<='z') s+=ch,r++,ch=getchar();
	return r;
}
int n,q,le[N];
vector<int> p[M];
const int P=131;
unsigned ll h[M];
unsigned ll hs1[M],hs2[M];
unsigned ll hsh1[M],hsh2[M];
inline unsigned ll h1(int l,int r){return hsh1[r]-hsh1[l-1]*h[r-l+1];}
inline unsigned ll h2(int l,int r){return hsh2[r]-hsh2[l-1]*h[r-l+1];}
inline unsigned ll gethash(string &s,int &len)
{
	unsigned ll r=1;
	for(int i=1;i<=len;i++) r=r*P+s[i];
	return r;
}
vector<int> g;
int lee[N],ppp1[N],ppp2[N];
struct node
{
	int len,ppppp1,ppppp2;
};
map<int,vector<node> > www;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	h[0]=1;
	for(int i=1;i<M;i++) h[i]=h[i-1]*P;
	scanf("%d%d",&n,&q);
	if(n<=100)
	{
		for(int i=1;i<=n;i++)
		{
			string s;
			le[i]=readstr(s);
			g.push_back(le[i]);
			p[le[i]].push_back(i);
			hs1[i]=gethash(s,le[i]);
			readstr(s);
			hs2[i]=gethash(s,le[i]);
		}
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		while(q--)
		{
			string s,t;
			int len=readstr(s);readstr(t);
			hsh1[0]=hsh2[0]=1;
			for(int i=1;i<=len;i++)
				hsh1[i]=hsh1[i-1]*P+s[i];
			for(int i=1;i<=len;i++)
				hsh2[i]=hsh2[i-1]*P+t[i];
			int ql=0,qr=0;
			for(int i=1;i<=len;i++)
				if(s[i]!=t[i]){ql=i;break;}
			for(int i=len;i>=1;i--)
				if(s[i]!=t[i]){qr=i;break;}
			int ans=0;
			for(int j:g)
			{
				if(j<qr-ql+1||j>len) continue;
				for(int i:p[j])
				{
					for(int l=max(1,qr-j+1),r=l+j-1;r<=len;l++,r++)
						if(h1(l,r)==hs1[i]-h[r-l+1]&&h2(l,r)==hs2[i]-h[r-l+1]) ans++;
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string s;
		lee[i]=readstr(s);
		for(int j=1;j<=lee[i];j++)
			if(s[j]=='b') ppp1[i]=j;
		readstr(s);
		for(int j=1;j<=lee[i];j++)
			if(s[j]=='b') ppp2[i]=j;
		www[ppp1[i]-ppp2[i]].push_back({lee[i],ppp1[i],ppp2[i]});
	}
	while(q--)
	{
		string s,t;
		int len=readstr(s);
		readstr(t);
		int P1=0,P2=0;
		for(int i=1;i<=len;i++)
			if(s[i]=='b') P1=i;
		for(int i=1;i<=len;i++)
			if(t[i]=='b') P2=i;
		int ans=0;
		for(node vx:www[P1-P2])
		{
			int le=vx.len,p1=vx.ppppp1,p2=vx.ppppp2;
			if(P1<=P2)
			{
				if(p1<=P1&&le-p2<=len-P2) ans++;
			}
			else
			{
				if(p2<=P2&&le-p1<=len-P1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 2
aab baa
aba baa
aab aab
baa aba
aaaaaab aaaabaa
aba baa
*/
