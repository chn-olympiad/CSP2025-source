#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define rep(i, l, r) for(int i = (l), END##i = (r); i <= END##i; ++i)
#define per(i, r, l) for(int i = (r), END##i = (l); i >= END##i; --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define ML debug("\n%.2lf MB\n", (&Med-&Mst)/1024.0/1024)
#define TL debug("\n%.2lf s\n", 1.0*clock()/CLOCKS_PER_SEC)
#define fileI(x) freopen(x, "r", stdin)
#define fileO(x) freopen(x, "w", stdout)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
bool Mst;
const int N=2e5+5,M=5e6+5,V=5e6+5;
int n,q,slen[N],ed1[N],ed2[N];
ll ans[N];
char t1[V],t2[V];
struct ACAM{
	int nV,ch[V][26],fa[V];
	int dfn[V],tim,ed[V];
	queue<int> que;
	struct Edge{ int to,nxt; }e[V];
	int head[V],elen;
	void InsertE(int u,int v){
		e[++elen]=Edge{v,head[u]};
		head[u]=elen;
	}

	void Ins(char s[],int &rem){
		int len=strlen(s+1),u=0,c;
		rep(i,1,len){
			c=s[i]-'a';
			if(!ch[u][c])ch[u][c]=++nV;
			u=ch[u][c];
		}
		rem=u;
	}
	void Build(){
		rep(i,0,25)if(ch[0][i])que.push(ch[0][i]);
		while(!que.empty()){
			int u=que.front();
			que.pop();
			InsertE(fa[u],u);
			rep(i,0,25){
				if(ch[u][i]){
					fa[ch[u][i]]=ch[fa[u]][i];
					que.push(ch[u][i]);
				}
				else{
					ch[u][i]=ch[fa[u]][i];
				}
			}
		}
	}
	void dfs(int u){
		dfn[u]=++tim;
		for(int i=head[u],v;i;i=e[i].nxt){
			v=e[i].to;
			dfs(v);
		}
		ed[u]=tim;
	}
}tr1,tr2;
struct Question{
	int a,b,c,tp,id;
	// >=a, <=b, <=c
}QQ[N]; //
bool cmpA(Question &x, Question &y){
	if(x.a!=y.a)return x.a<y.a;
	return x.tp<y.tp;
}
bool cmpB(Question &x, Question &y){
	return x.b<y.b;
//	return x.tp<y.tp;
}
int qcnt;
struct BIT{
	int t[N],col[N],flag;
	void init(){
		++flag;
	}
	void add(int x,int k){
//		debug("%d %d\n",x,tr2.tim);
		while(x<=tr2.tim){
			if(col[x]!=flag){
				t[x]=0;
				col[x]=flag;
			}
			t[x]+=k;
			x+=x&-x; 
		}
	}
	int ask(int x){
		int ret=0;
		while(x){
			if(col[x]!=flag){
				t[x]=0;
				col[x]=flag;
			}
			ret+=t[x];
			x-=x&-x;
		}
		return ret;
	}
}bit;
void CDQ(int l,int r){
	if(l==r)return;
	int mid=l+r>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	sort(QQ+l,QQ+mid+1,cmpB);
	sort(QQ+mid+1,QQ+r+1,cmpB);
	int j=mid+1;
//	bit.init();
//	rep(i,0,tr1.nV)assert(tr1.dfn[i]<=tr1.ed[i]);
//	rep(i,0,tr2.nV)assert(tr2.dfn[i]<=tr2.ed[i]);
	rep(i,l,mid){
		while(j<=r&&QQ[i].b>=QQ[j].b){
			if(QQ[j].tp==0){
				bit.add(QQ[j].c,QQ[j].id);
			}
			++j;
		}
		if(QQ[i].tp==1){
			ans[QQ[i].id]+=bit.ask(QQ[i].c);
		}
	}
	rep(k,mid+1,j-1){
		if(QQ[k].tp==0){
			bit.add(QQ[k].c,-QQ[k].id);
		}
	}
}

const int mod=1e9+7,base=13331;
int hsh1[N],hsh2[N],hsh3[N],hsh4[N],ex[2005];
ll Ghash3(int l,int r){
	return (hsh3[r]-1LL*hsh3[l-1]*ex[r-l+1]%mod+mod)%mod;
}
ll Ghash4(int l,int r){
	return (hsh4[r]-1LL*hsh4[l-1]*ex[r-l+1]%mod+mod)%mod;
}
bool Med;
int main(){
	fileI("replace.in");
	fileO("replace.out");
	ML;
	scanf("%d%d",&n,&q);
	int ck=0;
	ex[0]=1;
	rep(i,1,2000)ex[i]=1LL*ex[i-1]*base%mod;
	rep(i,1,n){
		scanf("%s",t1+1);
		slen[i]=strlen(t1+1);
		ck+=slen[i]*2;
		tr1.Ins(t1,ed1[i]);
		scanf("%s",t2+1);
		tr2.Ins(t2,ed2[i]);

		rep(j,1,slen[i]){
			hsh1[i]=(1LL*hsh1[i]*base+t1[j]-'a'+1)%mod;
			hsh2[i]=(1LL*hsh2[i]*base+t2[j]-'a'+1)%mod;
		}
	}
	if(n<=1000&&ck<=2000){
		while(q--){
			int l1,l2;
			scanf("%s%s",t1+1,t2+1);
//			debug("%s %s\n",t1+1,t2+1);
			l1=strlen(t1+1),l2=strlen(t2+1);
			if(l1!=l2){
				printf("0\n");
				continue;
			}
			int l=0,r;
			rep(i,1,l1){
				if(t1[i]!=t2[i]){
					if(!l)l=i;
					r=i;
				}
			}
			rep(i,1,l1){
				hsh3[i]=(1LL*hsh3[i-1]*base+t1[i]-'a'+1)%mod;
				hsh4[i]=(1LL*hsh4[i-1]*base+t2[i]-'a'+1)%mod;
			}
			ll ans=0;
			rep(i,1,n){
				rep(j,max(1,r-slen[i]+1),min(l,l1-slen[i]+1)){
					if(Ghash3(j,j+slen[i]-1)==hsh1[i]&&
						Ghash4(j,j+slen[i]-1)==hsh2[i]){
						ans++; 
					}
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	tr1.Build();
	tr2.Build();
	tr1.dfs(0);
	tr2.dfs(0);
	rep(i,1,n){
		int u1=ed1[i],u2=ed2[i];
		QQ[++qcnt]=Question{slen[i],tr1.ed[u1],tr2.ed[u2],0,1};
		QQ[++qcnt]=Question{slen[i],tr1.dfn[u1],tr2.ed[u2],0,-1};
		QQ[++qcnt]=Question{slen[i],tr1.ed[u1],tr2.dfn[u2]-1,0,-1};
		QQ[++qcnt]=Question{slen[i],tr1.dfn[u1]-1,tr2.dfn[u2]-1,0,1};
	}
	rep(tt,1,q){
		int u1=0,u2=0;
		int l1,l2;
		scanf("%s%s",t1+1,t2+1);
		l1=strlen(t1+1),l2=strlen(t2+1);
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		int l=0,r;
		rep(i,1,l1){
			if(t1[i]!=t2[i]){
				if(!l)l=i;
				r=i;
			}
		}
		rep(i,1,l1){
			u1=tr1.ch[u1][t1[i]-'a'];
			u2=tr2.ch[u2][t2[i]-'a'];
			if(i>=r){
				QQ[++qcnt]=Question{i-l+1,tr1.dfn[u1],tr2.dfn[u2],1,tt};
			}
		}
	}
//	debug("ef\n");
	sort(QQ+1,QQ+qcnt+1,cmpA);
	CDQ(1,qcnt);
//	debug("qcnt = %d\n",qcnt);
	rep(i,1,q)printf("%lld\n",ans[i]);
//	TL;
	return 0;
}
