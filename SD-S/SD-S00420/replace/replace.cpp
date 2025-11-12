#include <bits/stdc++.h>
using namespace std;
int n,q;
const int M=5e6+5,N=1e7+55;
char s1[M],s2[M]; 
struct node{
	int x,y;
};
vector<node> d[N];
struct Query{int x,y,id;};
vector<Query> Q[N];
int rt[N],lc[N],rc[N],t[N],idx=0;
int cle[N],ans[M],point=0;
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
void pushup(int u){
	t[u]=t[lc[u]]+t[rc[u]];
}
void upd1(int &u,int l,int r,int x,int k){
	if(!u) u=++idx;
	if(l==r){
		t[u]+=k;
		return ;
	}
	if(x<=mid) upd1(lc[u],l,mid,x,k);
	else upd1(rc[u],mid+1,r,x,k);
	pushup(u);
}
void update(int x,int y,int k){
	for(;x<=M*2;x+=lowbit(x)) upd1(rt[x],1,M,y,k),cle[++point]=x;
}
int q1(int u,int l,int r,int x,int y){
	if(!u) return 0;
	if(x<=l && r<=y) return t[u];
	int ans=q1(lc[u],l,mid,x,y);
	if(y>mid) ans+=q1(rc[u],mid+1,r,x,y);
	return ans;
}
int query(int x,int y){
	int res=0;
	for(;x;x-=lowbit(x)) res+=q1(rt[x],1,M,1,y);
	return res;
}
void init(){
	for(int i=1;i<=point;++i) rt[cle[i]]=0;
	point=0;
	for(int i=1;i<=idx;++i) t[i]=lc[i]=rc[i]=0;
	idx=0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
//	printf("AAA\n");
	for(int t=1;t<=n;++t){
		scanf("%s %s",s1+1,s2+1);
		int pos1,pos2,len=strlen(s1+1);
		for(int i=1;i<=len;++i) if(s1[i]=='b'){
			pos1=i; break;
		}
		for(int i=1;i<=len;++i) if(s2[i]=='b'){
			pos2=i; break;
		}
		d[pos2-pos1+M].push_back({pos1,len-pos1+1});
	}
//	printf("AAA\n");
	for(int t=1;t<=q;++t){
		scanf("%s %s",s1+1,s2+1);
		int pos1,pos2,len=strlen(s1+1);
		for(int i=1;i<=len;++i) if(s1[i]=='b'){
			pos1=i; break;
		}
		for(int i=1;i<=len;++i) if(s2[i]=='b'){
			pos2=i; break;
		}
		Q[pos2-pos1+M].push_back({pos1,len-pos1+1,t});
	}
//	printf("AAA\n");
	for(int i=1;i<=M*2;++i){
		init();
		for(node r:d[i]){
			update(r.x,r.y,1);
		}
		for(Query r:Q[i]){
			ans[r.id]=query(r.x,r.y);
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
