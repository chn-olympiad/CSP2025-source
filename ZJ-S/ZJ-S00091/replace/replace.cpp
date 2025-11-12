#include<bits/stdc++.h>
using namespace std;
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mp(x,y) make_pair(x,y)
#define ull unsigned long long
#define eb push_back
const int __=5e6+6,_=2e5+5,mod=1e9+9;
int n,cl,m,tl,Tl,t,al,bl,u,L,R,ans,sz,d[_],l[_],r[_],c,tr[__+_][26],Tr[__+_][26];
vector<int>s[_+__],S[_+__],o,O;
char a[__],b[__];
inline int rmod(int x){	return x-=mod,x+(x>>31&mod);}
struct H
{	ull a;
	int b;
	H(ull _a=0,int _b=0):a(_a),b(_b){}
	inline H operator+(const H o)const{	return H(a+o.a,rmod(b+o.b));}
	inline H operator+(const int o)const{	return H(a+o,rmod(b+o));}
	inline H operator*(const H o)const{	return H(a*o.a,1ll*b*o.b%mod);}
	inline bool operator<(const H o)const
	{	if(a!=o.a)	return a<o.a;
		return b<o.b;
	}
}	p,q,Q;
map<pair<H,H>,int>B;
signed main()
{	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	FIO("replace");
//	FIO("replace4");
	cin>>n>>m,p=H(29,31),tl=Tl=n;
	for(int i=1;i<=n;i++)
	{	cin>>a+1>>b+1,al=strlen(a+1),bl=strlen(b+1),L=1,R=al;
		while(L<=al&&a[L]==b[L])	L++;
		while(R&&a[R]==b[R])	R--;
		if(L<=R)
		{	l[++cl]=L,r[cl]=R,q=Q=H();
			for(int j=L;j<=R;j++)	q=(q*p)+(a[j]-'a'),Q=(Q*p)+(b[j]-'a');
			if(!B[mp(q,Q)])	B[mp(q,Q)]=++t;
			u=c=B[mp(q,Q)];
			for(int j=L-1;j;j--)
			{	if(!tr[u][a[j]-'a'])	tr[u][a[j]-'a']=++tl;
				u=tr[u][a[j]-'a'];
			}
			s[u].eb(cl);
			u=c;
			for(int j=R+1;j<=al;j++)
			{	if(!Tr[u][a[j]-'a'])	Tr[u][a[j]-'a']=++Tl;
				u=Tr[u][a[j]-'a'];
			}
			S[u].eb(cl);
		}
	}
	while(m--)
	{	cin>>a+1>>b+1,al=strlen(a+1),bl=strlen(b+1),o.clear(),O.clear();
		if(al!=bl)
		{	cout<<"0\n";
			continue;
		}
		L=1,R=al,q=Q=H();
		while(L<=al&&a[L]==b[L])	L++;
		while(R&&a[R]==b[R])	R--;
		for(int i=L;i<=R;i++)	q=(q*p)+(a[i]-'a'),Q=(Q*p)+(b[i]-'a');
		if(!B[mp(q,Q)])
		{	cout<<"0\n";
			continue;
		}
		u=c=B[mp(q,Q)],sz=s[u].size();
		for(int i=0;i<sz;i++)	o.eb(s[u][i]);
		for(int i=L-1;i;i--)
		{	if(!tr[u][a[i]-'a'])	break;
			u=tr[u][a[i]-'a'],sz=s[u].size();
			for(int j=0;j<sz;j++)	o.eb(s[u][j]);
		}
		u=c,sz=S[u].size();
		for(int i=0;i<sz;i++)	O.eb(S[u][i]);
		for(int i=R+1;i<=al;i++)
		{	if(!Tr[u][a[i]-'a'])	break;
			u=Tr[u][a[i]-'a'],sz=S[u].size();
			for(int j=0;j<sz;j++)	O.eb(S[u][j]);
		}
		sz=O.size();
		for(int i=0;i<sz;i++)	d[O[i]]=1;
		sz=o.size();
		for(int i=0;i<sz;i++)	ans+=d[o[i]];
		sz=O.size();
		for(int i=0;i<sz;i++)	d[O[i]]=0;
		cout<<ans<<'\n',ans=0;
	}
	return 0;
}
/*
fc replace3.out replace3.ans
*/
