#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#define pb push_back
#define LL long long
const int maxn=200005;
const int maxm=5000005;
const int vp=29;
const int mod=1e9+7;
using namespace std;
struct pii {LL fr,se;};
bool operator < (pii a,pii b) {return a.fr==b.fr?a.fr<b.fr:a.se<b.se;}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
string s,ss;
LL cf[5000005];
struct hokuto {LL a,b,c,d;}Q[maxn];
map<LL,LL>lst,lf;
vector<hokuto>p1[maxm],p2[maxm];
map<hokuto,int>len,len2,val;
LL QQ[maxn];
vector<int>pp[maxm];
map<LL,int>ls,vs;
bool operator < (hokuto a,hokuto b)
{
	if (a.a!=b.a) return a.a<b.a;
	if (a.b!=b.b) return a.b<b.b;
	return a.c!=b.c?a.c<b.c:a.d<b.d;
}
bool cmp(pair<hokuto,int> a,pair<hokuto,int>b)
{
	return a.second!=b.second?a.second<b.second:a.first<b.first;
}
int vis[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	int bst=5000000;
	cf[0]=1;for (int i=1;i<=bst;i++) cf[i]=cf[i-1]*vp%mod;
	for (int i=1;i<=n;i++)
	{
		cin>>s>>ss;
		int l=s.size();
		if (s==ss)
		{
			LL vn=0;
			for (int i=l-1;~i;i--)
			{
				LL a=vn;
				vn=(cf[l-i-1]*(s[i]-'a'+1)+a)%mod;
				lf[vn]=a;
			}
			vn=0;
			for (int i=0;i<l;i++)
			{
				LL a=vn;
				vn=(vn*vp+s[i]-'a'+1)%mod;
				lst[vn]=a;ls[vn]=ls[a]+1;
			}
			vs[vn]++;
			continue;
		}
		LL vs=0,vss=0,bf=0,af=0;
		int st=0;
		for (;st<l;st++) if (s[st]!=ss[st]) break;
		for (int j=st-1;~j;j--)
		{
			LL a=bf;
			bf=(bf*vp+s[j]-'a'+1)%mod;
			lst[bf]=a;
		}
		int ed=l-1;
		for (;~ed;ed--) if (s[ed]!=ss[ed]) break;
		for (int j=ed+1;j<l;j++)
		{
			LL a=af;
			af=(af*vp+s[j]-'a'+1)%mod;
			lst[af]=a;
		}
		for (int p=st;p<=ed;p++)
		{
			vs=(vs*vp+s[p]-'a'+1)%mod;
			vss=(vss*vp+ss[p]-'a'+1)%mod;
		}
		val[{vs,vss,bf,af}]++;
		LL naf=0,nbf=0;
		for (int j=st-1;~j;j--)
		{
			LL a=nbf;
			nbf=(nbf*vp+s[j]-'a'+1)%mod;
			len2[{vs,vss,nbf,af}]=len2[{vs,vss,a,af}]+1;
		}
		for (int j=ed+1;j<l;j++)
		{
			LL a=naf;
			naf=(naf*vp+s[j]-'a'+1)%mod;
			len[{vs,vss,bf,naf}]=len[{vs,vss,bf,a}]+1;
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>s>>ss;
		int l=s.size();
		if (s==ss)
		{
			vis[i]=1;
			LL vn=0;
			for (int i=l-1;~i;i--)
			{
				LL a=vn;
				vn=(cf[l-i-1]*(s[i]-'a'+1)+a)%mod;
				lf[vn]=a;
			}
			vn=0;
			for (int i=0;i<l;i++)
			{
				LL a=vn;
				vn=(vn*vp+s[i]-'a'+1)%mod;
				lst[vn]=a;ls[vn]=ls[a]+1;
			}
			QQ[i]=vn;
			continue;
		}
		LL vs=0,vss=0,bf=0,af=0;
		int st=0;
		for (;st<l;st++) if (s[st]!=ss[st]) break;
		for (int j=st-1;~j;j--)
		{
			int a=bf;
			bf=(bf*vp+s[j]-'a'+1)%mod;
			lst[bf]=a;
		}
		int ed=l-1;
		for (;~ed;ed--) if (s[ed]!=ss[ed]) break;
		for (int j=ed+1;j<l;j++)
		{
			int a=af;
			af=(af*vp+s[j]-'a'+1)%mod;
			lst[af]=a;
		}
		for (int p=st;p<=ed;p++)
		{
			vs=(vs*vp+s[p]-'a'+1)%mod;
			vss=(vss*vp+ss[p]-'a'+1)%mod;
		}
		LL naf=0,nbf=0;
		for (int j=st-1;~j;j--)
		{
			int a=nbf;
			nbf=(nbf*vp+s[j]-'a'+1)%mod;
			len2[{vs,vss,nbf,af}]=len2[{vs,vss,a,af}]+1;
		}
		for (int j=ed+1;j<l;j++)
		{
			int a=naf;
			naf=(naf*vp+s[j]-'a'+1)%mod;
			len[{vs,vss,bf,naf}]=len[{vs,vss,bf,a}]+1;
		}
		Q[i]={vs,vss,bf,af};
	}
	for (auto a:len) p1[a.second].pb(a.first);
	for (int i=1;i<=bst;i++) for (auto p:p1[i]) val[{p.a,p.b,p.c,p.d}]+=val[{p.a,p.b,p.c,lst[p.d]}];
	for (auto a:len2) p2[a.second].pb(a.first);
	for (int i=1;i<=bst;i++) for (auto p:p2[i]) val[{p.a,p.b,p.c,p.d}]+=val[{p.a,p.b,lst[p.c],p.d}];
	for (auto a:ls) pp[a.second].pb(a.first);
	for (int i=1;i<=bst;i++) for (auto p:pp[i]) vs[p]+=vs[lst[p]];
	for (int i=1;i<=bst;i++) for (auto p:pp[i]) vs[p]+=vs[lf[p]];
	for (int i=1;i<=q;i++)
	{
		if (vis[i]) write(vs[QQ[i]]);
		else write(val[Q[i]]);
		putchar('\n');
	}
	return 0;
}
/*
注意到这是找本质不同的区间
*/
