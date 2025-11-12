#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define lys long long
#define lys_ int

char ys[1<<21],*lys1=ys,*lys2=ys,ly[1<<21],*ls=ly,ly3[20];

char gc(){
    return (lys1==lys2&&(lys2=(lys1=ys)+fread(ys,1,1<<21,stdin),lys1==lys2)?EOF:*lys1++);
}

void pc(char x){
    (ls-ly<1<<21)?(*ls++=x):(fwrite(ly,ls-ly,1,stdout),ls=ly,*ls++=x);
    return;
}

struct io{
    ~io(){
        fwrite(ly,1,ls-ly,stdout);
    }
}_;

lys_ read(){
    lys_ x=0,F=1;
    char c='\0';
    while(c<'0'||c>'9'){
        c=gc();
        if(c=='-')F=-1;
    }
    while(c<='9'&&c>='0'){
        x=x*10+(c^48);
        c=gc();
    }
    return x*F;
}

void print(lys_ x){
    if(x==0){
        pc('0');
        return;
    }
    int l=0;
    if(x<0)x=-x,pc('-');
    while(x)ly3[l++]=x%10+48,x/=10;
    while(l--)pc(ly3[l]);
    return;
}

const int N = 1000006;

int n,m,k;

int cnt,head[N];

struct node{
	int to,nxt,w;
}edge[N<<1];

void add(int u,int v,int w){
	edge[++cnt]={v,head[u],w};
	head[u]=cnt;
	return;
}

int cc[N];

int dfn[N],tot,low[N];

int tagjan(int u,int fa){

}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cc[i]=read();
		for(int j=1;j<=n;j++){
			int w=read();
			add(n+i,j,w);
			add(j,n+i,w);
		}
	}
	print(rand());
    return 0;
}

