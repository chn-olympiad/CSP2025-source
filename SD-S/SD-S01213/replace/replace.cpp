#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template <typename ty>
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T>
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
const int N=5e6+10,M=2e5+50;
const int MOD1=1e9+9,MOD2=1e9+31;
const ll ch1=89,ch2=199;
int tr[N<<1][26],nodecnt;
char s1[N],s2[N];
struct Node{
	ll hsh1,hsh2;
	int x,y,ty;
}a[M<<1];
int Ans[M];
int Ins(char *s,int l,int r) {
	int p=0;
	for(int i=l;i<=r;i++) {
		int v=s[i]-'a';
		if(!tr[p][v]) tr[p][v]=++nodecnt;
		p=tr[p][v];
	}
	return p;
}
int c[N<<1];
#define lowbit(x) ((x)&(-x))
void add(int x,int i) {
	while(i<=nodecnt+1) {
		c[i]+=x;
		i+=lowbit(i);
	}
} 
int query(int i) {
	int ans=0;
	while(i) {
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}
int L[N<<1],R[N<<1],dfncnt;
void dfs(int u) {
	L[u]=++dfncnt;
	for(int i=0;i<26;i++) 
		if(tr[u][i]) dfs(tr[u][i]);
	R[u]=dfncnt; 
}
struct AWA{
	int x,y,qid,w;
}awa[M*5];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	read(n,q);
	int pos=0;
	for(int i=1;i<=n;i++) {
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1); bool flag=false;
		for(int j=1;j<=len;j++) 
			if(s1[j]!=s2[j]) flag=true;
		if(!flag) continue;
		int l=1,r=len;
		while(s1[l]==s2[l]) l++;
		while(s1[r]==s2[r]) r--;
		ll hsh1=0,hsh2=0;
		for(int i=l;i<=r;i++) {
			hsh1=(hsh1*ch1+s1[i])%MOD1;
			hsh2=(hsh2*ch2+s1[i])%MOD1;
		}
		for(int i=l;i<=r;i++) {
			hsh1=(hsh1*ch1+s2[i])%MOD2;
			hsh2=(hsh2*ch2+s2[i])%MOD2;
		}
		reverse(s1+1,s1+l);
		a[++pos]={hsh1,hsh2,Ins(s1,1,l-1),Ins(s2,r+1,len),0};
	}
	for(int i=1;i<=q;i++) {
		scanf("%s%s",s1+1,s2+1);
		int len1=strlen(s1+1);
		int len2=strlen(s2+1);
		if(len1!=len2) continue;
		int len=len1;
		int l=1,r=len;
		while(s1[l]==s2[l]) l++;
		while(s1[r]==s2[r]) r--;
		ll hsh1=0,hsh2=0;
		for(int i=l;i<=r;i++) {
			hsh1=(hsh1*ch1+s1[i])%MOD1;
			hsh2=(hsh2*ch2+s1[i])%MOD1;
		}
		for(int i=l;i<=r;i++) {
			hsh1=(hsh1*ch1+s2[i])%MOD2;
			hsh2=(hsh2*ch2+s2[i])%MOD2;
		}
		reverse(s1+1,s1+l);
		a[++pos]={hsh1,hsh2,Ins(s1,1,l-1),Ins(s2,r+1,len),i};
	}
	dfs(0);
//	assert(dfncnt==nodecnt+1);
	sort(a+1,a+pos+1,[&](const Node x,const Node y) {
		if(x.hsh1!=y.hsh1) return x.hsh1<y.hsh1;
		if(x.hsh2!=y.hsh2) return x.hsh2<y.hsh2;
		return x.ty<y.ty;
	});
	for(int l=1,r;l<=pos;l=r+1) {
		r=l;
		while(r<pos&&a[r+1].hsh1==a[l].hsh1&&a[r+1].hsh2==a[l].hsh2) ++r;
//		assert(a[l].hsh==a[r].hsh);
//		if(l<r)cerr<<l<<" "<<r<<endl;
		int tot=0;
		for(int i=l;i<=r;i++) {
			if(a[i].ty==0) {
				awa[++tot]={L[a[i].x],L[a[i].y],0,1};
				awa[++tot]={L[a[i].x],R[a[i].y]+1,0,-1};
				awa[++tot]={R[a[i].x]+1,L[a[i].y],0,-1};
				awa[++tot]={R[a[i].x]+1,R[a[i].y]+1,0,1};
			}else awa[++tot]={L[a[i].x],L[a[i].y],a[i].ty,0};
		}
		sort(awa+1,awa+tot+1,[&](const AWA x,const AWA y) {
			if(x.x!=y.x) return x.x<y.x;
			return x.qid<y.qid;
		});
		for(int i=1;i<=tot;i++) {
			if(!awa[i].qid) add(awa[i].w,awa[i].y);
			else Ans[awa[i].qid]+=query(awa[i].y);
		}
	}
	for(int i=1;i<=q;i++) 
		printf("%d\n",Ans[i]);
	return 0;
}
