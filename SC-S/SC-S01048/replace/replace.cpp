#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
typedef unsigned long long ull; // 用作哈希 
const ull P1=1999,P2=2017;
const int LEN=6e6+5,N=1e6+5;
int n,q;
/*
1. 着重注意数组空间 
2. 注意二元组相等的问题  v
3. 注意 t 不相等的问题  v
ulimit -v 2000000
*/

struct pair{
	int x,y;
};
int dfn[LEN*2],dlen,rgt[LEN*2];
struct side{
	int nxt,v;
	char t;
}s[LEN*2];
int p[LEN*2],slen;
void push(int u,int v,char t){
	s[++slen]={p[u],v,t};
	p[u]=slen;
	return ;
}
std::map<ull ,std::map<ull ,pair > > rt;
int trlen;
ull hash(char *s,char *t,const int& p){
	ull hs=0;
	while(s!=t){
		hs*=p;
		hs+=*s;
		++s;
	}
	return hs;
}

int addpush(int x,char *st,int stp){ // 加入一个点 
	if(!x) puts("									ah?");
	if(!(*st)){
		return x;
	}for(int i=p[x];i;i=s[i].nxt) if(s[i].t==(*st)){
		return addpush(s[i].v,st+stp,stp);
	}push(x,++trlen,*st);
	return addpush(trlen,st+stp,stp);
}


void build(int x){
	if(dfn[x]) return ;
	dfn[x]=++dlen;
	for(int i=p[x];i;i=s[i].nxt){
//		printf("%d - %c > %d\n", x, s[i].t, s[i].v);
		build(s[i].v);
	}rgt[x]=dlen;
	return ;
}

char str1[LEN],str2[LEN];
pair need[N],mod[N],que[N];
int neen;
pair news(){
	int len=strlen(str1+1);
	if(strlen(str2+1)!=len) return {0,0};
	int head=1,tail=len;
	while(str1[head]&&str1[head]==str2[head]) ++head;
	while(str1[tail]&&str1[tail]==str2[tail]) --tail;
	if(head>tail) return {0,0};
	ull h1=hash(str1+head,str1+tail+1,P1);
	ull h2=hash(str2+head,str2+tail+1,P2);
//	printf("%d~%d:%llu %llu\n", head, tail, h1, h2);
	pair &t=rt[h1][h2],re={0,0};
	if(!t.x) t={++trlen,++trlen},need[++neen]=t;
	re.x=addpush(t.x,str1+head-1,-1);
	re.y=addpush(t.y,str2+tail+1,1);
	return re;
}

struct blk{
	int x,l,r,op;
	bool operator<(const blk &vr) const{
		if(x==vr.x){
			return op<vr.op; // 询问用 2，第 l 个询问为 r 
		}
		return x<vr.x;
	}
}oper[N];
int olen;
void sqr(int U,int D,int L,int R){
	oper[++olen]={U,L,R,1};
	oper[++olen]={D+1,L,R,-1};
	return ;
}int gans[N];

// 服务于扫描线的线段树 
int ml,mr,mv,mi;
int tag[LEN*4];
void date(int x,int tg){
	tag[x]+=tg;
	return ;
}void down(int x){
	int bx=x<<1;
	date(bx,tag[x]);
	date(bx^1,tag[x]);
	tag[x]=0;
	return ;
}
void modify(int x=1,int l=1,int r=trlen){
	if(ml<=l&&r<=mr){
		date(x,mv);
		return ;
	}int mid=(l+r)>>1,bx=x<<1;
	down(x);
	if(ml<=mid) modify(bx,l,mid);
	if(mr>mid) modify(bx^1,mid+1,r);
	return ;
}int find(int x=1,int l=1,int r=trlen){
	if(l==r) return tag[x];
	int mid=(l+r)>>1,bx=x<<1;
	down(x);
	if(mi<=mid) return find(bx,l,mid);
	return find(bx^1,mid+1,r);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;++i){
		scanf("%s%s", str1+1,str2+1);
		mod[i]=news();
	}for(int i=1;i<=q;++i){
		scanf("%s%s", str1+1,str2+1);
		que[i]=news();
	}for(int i=1;i<=neen;++i){
//		printf("build:%d %d\n", need[i].x, need[i].y);
		build(need[i].x);
		build(need[i].y);
	}for(int i=1;i<=n;++i) if(mod[i].x){
//		printf("-> %d %d %d %d\n", mod[i].x, dfn[mod[i].x], mod[i].y, dfn[mod[i].y]);
		sqr(dfn[mod[i].x],rgt[mod[i].x],dfn[mod[i].y],rgt[mod[i].y]);
	}for(int i=1;i<=q;++i) if(que[i].x){
		oper[++olen]={dfn[que[i].x],i,dfn[que[i].y],2};
	}
	std::sort(oper+1,oper+olen+1);
	for(int i=1;i<=olen;++i){
		if(oper[i].op==2){
			mi=oper[i].r;
			gans[oper[i].l]=find();
//			printf("find:%d\n", mi);
		}else{
			ml=oper[i].l,mr=oper[i].r,mv=oper[i].op;
//			printf("modify:%d %d %d\n", ml, mr, mv);
			modify();
		}
	}for(int i=1;i<=q;++i) printf("%d\n", gans[i]);
	return 0;
} 