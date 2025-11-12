#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7;

int in(){
	int k=0,t=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10),putchar(x%10+'0');
}
struct node{
	int nxt,to,w,u;
}e[100000001];
int head[N];//,w[N],to[N],nxt[N];
int n,m,k,tot;

void add(int u,int v,int ww){
	e[++tot].nxt=head[u];
	e[tot].to=v;
	e[tot].u=u;
	e[tot].w=ww;
	head[u]=tot;
}

int fa[N];

int get(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=get(fa[x]);
}

void merge(int x,int y){
	fa[get(x)]=get(y);
}

bool cmp(node a,node b){
	return a.w<b.w;
}
int c[N][N],d[N],cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in();m=in();k=in();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,ww;
		u=in();v=in();ww=in();
		add(u,v,ww);
		add(v,u,ww);
		cnt+=2;
	}
	cnt=n;
	for(int i=1;i<=k;i++){
		d[i]=in();
		for(int j=1;j<=n;j++){
			c[i][j]=in();
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(x==y)continue;
				add(x,y,c[i][x]+c[i][y]);
				cnt++;
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int num=0,ans=0;
	for(int i=1;i<=cnt;i++){
	//	if(num==n)break;
		if(get(e[i].to)!=get(e[i].u)){
			merge(e[i].to,e[i].u);
			num++;
			ans+=e[i].w;
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4


*/