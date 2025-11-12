#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

typedef unsigned long long ull;

const int N=5e6+10,Pl=3,MOD=9989899;

struct Hsh{
	ull x[Pl];
	Hsh(ull a=0){x[0]=x[1]=x[2]=a;}
	Hsh(ull a,ull b,ull c){x[0]=a,x[1]=b,x[2]=c;}
	int get(){
		return (x[0]+x[1]+x[2])%MOD;
	}
	Hsh operator*(const Hsh &o)const{
		return {x[0]*o.x[0],x[1]*o.x[1],x[2]*o.x[2]};
	}
	Hsh operator+(const Hsh &o)const{
		return {x[0]+o.x[0],x[1]+o.x[1],x[2]+o.x[2]};
	}
	bool operator==(const Hsh &o)const{
		return x[0]==o.x[0]&&x[1]==o.x[1]&&x[2]==o.x[2];
	}
}P(998244353,131,1000000007);
int cnt[N];
struct Trie{
	int tr[N][26],idx;
	int ed[N],ne[N],h[N],eidx;
	void add(int rt,char *s,int id){
		int p=rt;
		for(int i=0;s[i];++i){
			int o=s[i]-'a';
			if(!tr[p][o]) tr[p][o]=++idx;
			p=tr[p][o];
//			printf("%d ",p);
		}
//		printf("\n%d %d\n",p,id);
		ed[++eidx]=id,ne[eidx]=h[p],h[p]=eidx;
	}
	int qry(int rt,char *s,int op){
		int res=0;
		int p=rt;
		for(int j=h[p];j;j=ne[j])
			res+=((cnt[ed[j]]+=op)==2);//,printf("-- %d %d %d\n",ed[j],cnt[ed[j]],res);
		for(int i=0;s[i];++i){
			int o=s[i]-'a';
			p=tr[p][o];
//			printf("%d %c\n",p,s[i]);
			if(!p) return res;
			for(int j=h[p];j;j=ne[j])
				res+=((cnt[ed[j]]+=op)==2);//,printf("-- %d %d %d\n",ed[j],cnt[ed[j]],res);
		}
//		puts("");
		return res;
	}
}A,B;

int n,q;
char s[2][N],t[N];
Hsh to[N][2];
int lrt[N],rrt[N],ne[N],h[MOD+10],idx;

int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
void read(char *s){
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') *(s++)=c,c=getchar();
	*s=0;
}
int add(Hsh a,Hsh b){
	int c=(a*b).get();
	for(int i=h[c];i;i=ne[i])
		if(to[i][0]==a&&to[i][1]==b)
			return i;
	to[++idx][0]=a,to[idx][1]=b,lrt[idx]=++A.idx,rrt[idx]=++B.idx,ne[idx]=h[c],h[c]=idx;
	return idx;
}
int qry(Hsh a,Hsh b){
	int c=(a*b).get();
	for(int i=h[c];i;i=ne[i])
		if(to[i][0]==a&&to[i][1]==b)
			return i;
	return 0;
}
int main(){
	Fre("replace");
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		read(s[0]+1),read(s[1]+1);
		int len=strlen(s[0]+1);
		int l=1,r=len;
		while(l<=len&&s[0][l]==s[1][l]) ++l;
		while(r>=1&&s[0][r]==s[1][r]) --r;
		if(l<=r){
//			printf("------------- %d %d\n",l,r);
			Hsh t1,t2;
//			printf("%llu %llu %llu %llu %llu %llu\n",t1.x[0],t1.x[1],t1.x[2],t2.x[0],t2.x[1],t2.x[2]);
			for(int i=l;i<=r;++i) t1=t1*P+Hsh(s[0][i]),t2=t2*P+Hsh(s[1][i]);//,printf("%c%c\n",s[0][i],s[1][i]),
//			printf("%llu %llu %llu %llu %llu %llu\n",t1.x[0],t1.x[1],t1.x[2],t2.x[0],t2.x[1],t2.x[2]);
			int tmp=add(t1,t2);
			for(int i=l-1;i;--i) t[l-i-1]=s[0][i];
			t[l-1]=0;
			A.add(lrt[tmp],t,i);
			for(int i=r+1;i<=len;++i) t[i-r-1]=s[0][i];
			t[len-r]=0;
			B.add(rrt[tmp],t,i);
		}
	}
	for(int i=1;i<=q;++i){
		read(s[0]+1),read(s[1]+1);
		int len=strlen(s[0]+1),len2=strlen(s[1]+1);
		if(len!=len2){
			puts("0");
			continue;
		}
		int l=1,r=len;
		while(s[0][l]==s[1][l]) ++l;
		while(s[0][r]==s[1][r]) --r;
		Hsh t1,t2;
		for(int i=l;i<=r;++i) t1=t1*P+Hsh(s[0][i]),t2=t2*P+Hsh(s[1][i]);//,printf("%c%c\n",s[0][i],s[1][i]);
		int tmp=qry(t1,t2);
		if(!tmp){
			puts("0");
			continue;
		}
		for(int i=l-1;i;--i) t[l-i-1]=s[0][i];
		t[l-1]=0;
		A.qry(lrt[tmp],t,1);
		for(int i=r+1;i<=len;++i) t[i-r-1]=s[0][i];
		t[len-r]=0;
		int res=B.qry(rrt[tmp],t,1);
		for(int i=l-1;i;--i) t[l-i-1]=s[0][i];
		t[l-1]=0;
		A.qry(lrt[tmp],t,-1);
		for(int i=r+1;i<=len;++i) t[i-r-1]=s[0][i];
		t[len-r]=0;
		B.qry(rrt[tmp],t,-1);
		printf("%d\n",res);
	}
	
	return 0;
}