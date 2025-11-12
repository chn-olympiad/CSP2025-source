#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define mk make_pair
#define x first
#define y second
#define N 400005
#define M 5000005
#define mod 1000000009
#define bas1 233
#define bas2 19260817
using namespace std;
struct mint{
	int x;
	mint(ll y=0,bool fg=0){
		if(fg)x=(int)(y);
		else x=(int)((y%mod+mod)%mod);
	}
	friend mint ksm(mint a,ll b);
	const mint inv(){
		return ksm(*this,mod-2);
	}
};
mint operator +(const mint a,const mint b){
	int res=a.x+b.x;
	if(res>=mod)res-=mod;
	return mint(res,1);
}
mint operator -(const mint a,const mint b){
	int res=a.x-b.x;
	if(res<0)res+=mod;
	return mint(res,1);
}
mint operator *(const mint a,const mint b){
	return mint(1ll*a.x*b.x%mod,1);
}
mint operator +=(mint &a,const mint b){
	a=a+b;
	return a;
}
mint operator -=(mint &a,const mint b){
	a=a-b;
	return a;
}
mint operator *=(mint &a,const mint b){
	a=a*b;
	return a;
}
istream& operator >>(istream &in,mint &b){
	ll y;in>>y;
	b=mint(y);
	return in;
}
ostream& operator <<(ostream &out,mint b){
	return out<<b.x;
}
mint ksm(mint a,ll b){
	mint res=1;
	for(;b;b>>=1,a*=a)
		if(b&1)res*=a;
	return res;
}
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];
array<int,4> w[N];
vector<int> gua[N];
int ch[M][26],tot,dfn[M],siz[M];
int gg;
void clr(){
	gg=0;
	for(int i=1;i<=tot;++i){
		for(int j=0;j<26;++j){
			ch[i][j]=0;
		}
		dfn[i]=siz[i]=0;
	}
	tot=1;
}
void ins(string s){
	int now=1;
	for(char c:s){
		if(!ch[now][c-'a'])ch[now][c-'a']=++tot;
		now=ch[now][c-'a'];
	}
}
void dfs(int u){
	dfn[u]=++gg;
	siz[u]=1;
	for(int i=0;i<26;++i){
		if(!ch[u][i])continue;
		dfs(ch[u][i]);
		siz[u]+=siz[ch[u][i]];
	}
}
ll ans[N];
struct uu{
	int l1,r1,l2,r2;
}xiu1[N*2];
struct ss{
	int op,x,l,r,val;
};
bool cmp(ss a,ss b){
	if(a.x!=b.x)return a.x<b.x;
	return a.op<b.op;
}
int tree[M];
void add(int k,int p){
	for(;k<=tot+3;k+=lowbit(k))tree[k]+=p;
}
int query(int k){
	int ans=0;
	for(;k;k-=lowbit(k))ans+=tree[k];
	return ans;
}
PII mei[N*2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int sum=0;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		sum+=s1[i].size();
		s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		if(s1[i]!=s2[i]){
			int l,r;
			mint sum1=0,sum2=0,sum3=0,sum4=0;
			for(int j=1;j<s1[i].size();++j){
				if(s1[i][j]!=s2[i][j]){
					l=j;break;
				}
			}
			for(int j=1;j<s1[i].size();++j){
				if(s1[i][j]!=s2[i][j]){
					r=j;
				}
			}
			for(int j=l;j<=r;++j){
				sum1=sum1*bas1+s1[i][j]-'a';
				sum2=sum2*bas2+s1[i][j]-'a';
				sum3=sum3*bas1+s2[i][j]-'a';
				sum4=sum4*bas2+s2[i][j]-'a';
			}
			w[i]={sum1.x,sum2.x,sum3.x,sum4.x};
			mei[i]=mk(l,r);
		}
	}	
//	cerr<<sum<<"kk\n";
	sort(w+1,w+n+1);
	int cnt=unique(w+1,w+n+1)-w-1;
	for(int i=1;i<=n;++i){
		if(s1[i]!=s2[i]){
			int l,r;
			mint sum1=0,sum2=0,sum3=0,sum4=0;
			for(int j=1;j<s1[i].size();++j){
				if(s1[i][j]!=s2[i][j]){
					l=j;break;
				}
			}
			for(int j=1;j<s1[i].size();++j){
				if(s1[i][j]!=s2[i][j]){
					r=j;
				}
			}
			for(int j=l;j<=r;++j){
				sum1=sum1*bas1+s1[i][j]-'a';
				sum2=sum2*bas2+s1[i][j]-'a';
				sum3=sum3*bas1+s2[i][j]-'a';
				sum4=sum4*bas2+s2[i][j]-'a';
			}
			array<int,4> ww={sum1.x,sum2.x,sum3.x,sum4.x};
			int wei=lower_bound(w+1,w+cnt+1,ww)-w;
			gua[wei].push_back(i);
			mei[i]=mk(l,r);
		}
	}
	for(int i=1;i<=q;++i){
		cin>>t1[i]>>t2[i];
		t1[i]=" "+t1[i],t2[i]=" "+t2[i];
		if(t1[i].size()!=t2[i].size())continue;
		int l,r;
		for(int j=1;j<t1[i].size();++j){
			if(t1[i][j]!=t2[i][j]){
				l=j;break;
			}
		}
		for(int j=1;j<t1[i].size();++j){
			if(t1[i][j]!=t2[i][j]){
				r=j;
			}
		}
		mint sum1=0,sum2=0,sum3=0,sum4=0;
		for(int j=l;j<=r;++j){
			sum1=sum1*bas1+t1[i][j]-'a';
			sum2=sum2*bas2+t1[i][j]-'a';
			sum3=sum3*bas1+t2[i][j]-'a';
			sum4=sum4*bas2+t2[i][j]-'a';
		}
		mei[i+n]=mk(l,r);
		array<int,4> ww={sum1.x,sum2.x,sum3.x,sum4.x};
		int wei=lower_bound(w+1,w+cnt+1,ww)-w;
		if(ww==w[wei]){
			gua[wei].push_back(i+n);
		}
	}
	for(int i=1;i<=cnt;++i){
		clr();
		for(int id:gua[i]){
//			cerr<<id<<" ";
			if(id<=n){
				int l=mei[id].x,r=mei[id].y;
				string xin="";
				for(int j=l-1;j>=1;--j){
					xin+=s1[id][j];
				}
//				cerr<<xin<<"uu\n";
				ins(xin);
			}
		}
		dfs(1);
		for(int id:gua[i]){
//			cerr<<id<<" ";
			if(id>n){
				int l=mei[id].x,r=mei[id].y;
				int now=1;
//				cerr<<id<<" "<<l<<" "<<r<<"oo\n";
				for(int j=l-1;j>=1;--j){
					if(!ch[now][t1[id-n][j]-'a']){
						break;
					}
					now=ch[now][t1[id-n][j]-'a'];
				}
				xiu1[id].l1=dfn[now];
			}
			else{
				int l=mei[id].x,r=mei[id].y;
				int now=1;
				for(int j=l-1;j>=1;--j){
					now=ch[now][s1[id][j]-'a'];
				}
				xiu1[id].l1=dfn[now],xiu1[id].r1=dfn[now]+siz[now]-1;
			}
		}
		clr();
		for(int id:gua[i]){
//			cerr<<id<<" ";
			if(id<=n){
				int l=mei[id].x,r=mei[id].y;
				string xin="";
				for(int j=r+1;j<s1[id].size();++j){
					xin+=s1[id][j];
				}
				ins(xin);
			}
		}
		dfs(1);
		for(int id:gua[i]){
//			cerr<<id<<" ";
			if(id>n){
				int l=mei[id].x,r=mei[id].y;
				int now=1;
				for(int j=r+1;j<t1[id-n].size();++j){
					if(!ch[now][t1[id-n][j]-'a']){
						break;
					}
					now=ch[now][t1[id-n][j]-'a'];
				}
				xiu1[id].l2=dfn[now];
			}
			else{
				int l=mei[id].x,r=mei[id].y;
				int now=1;
				for(int j=r+1;j<s1[id].size();++j){
					now=ch[now][s1[id][j]-'a'];
				}
				xiu1[id].l2=dfn[now],xiu1[id].r2=dfn[now]+siz[now]-1;
			}
		}
		vector<ss> qq;
		for(int id:gua[i]){
			if(id>n){
				qq.push_back({1,xiu1[id].l1,xiu1[id].l2,id-n,0});
			}
			else{
				qq.push_back({0,xiu1[id].l1,xiu1[id].l2,xiu1[id].r2,1});
				qq.push_back({0,xiu1[id].r1+1,xiu1[id].l2,xiu1[id].r2,-1});
			}
		}
		sort(qq.begin(),qq.end(),cmp);
		for(ss o:qq){
//			cerr<<o.op<<' '<<o.l<<' '<<o.r<<' '<<o.val<<"oo\n";
			if(o.op==0){
				add(o.l,o.val);
				add(o.r+1,-o.val);
			}
			else{
				ans[o.r]=query(o.l);
			}
		}
		for(ss o:qq){
			if(o.op==0){
				add(o.l,-o.val);
				add(o.r+1,o.val);
			}
		}
	}
	for(int i=1;i<=q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
