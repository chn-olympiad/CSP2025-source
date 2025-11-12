#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=1e4+15,M=1e6+5;
struct node{
	int x,y,v;
}e[M],e2[N*10],a[10][N];
int n,m,k,I,ans=1e18;
int c[10],fa[N],T[10];
bool cmp(node i,node j){return i.v<j.v;}
void init(int x){for(int i=0;i<=n+x;i++) fa[i]=i;}
int finds(int x){
	if(x==fa[x]) return x;
	return fa[x]=finds(fa[x]);
}
node Top(){
	int p=-1,sum=1e18;
	for(int i=0;i<k;i++){
		if(T[i]<=n){
			if(a[i][T[i]].v<sum) sum=a[i][T[i]].v,p=i;
		}
	}
	if(p==-1&&I>m) return {0,0,-1};
	if(p==-1) return e[I++];
	if(I>m) return a[p][T[p]++];
	if(e[I].v<=a[p][T[p]].v) return e[I++];
	return a[p][T[p]++];
}
void kruskal(int X){
	int cnt=0,vis[k],Y=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<k;i++){
		if(X&(1<<i)) vis[i]=1;
	}
	for(int i=0;i<k;i++){
		if(vis[i]) cnt+=c[i],Y++;
	}
	if(cnt>=ans) return ;
	int f=0;
	for(int i=0;i<k;i++){
		if(vis[i]){
			for(int j=1;j<=n;j++){
				e2[++f]=a[i][j];
			}
		}
	}
	sort(e2+1,e2+f+1,cmp);
	init(Y);
	int bian=0,i=1,j=1;I=1;
	for(int j=0;j<k;j++){
		if(vis[j]) T[j]=1;
		else T[j]=n+1;
	}
	while(bian<n+Y-1){
		if(i>m&&j>f) return ;
		node leaf;
		if(j>f||e[i].v<e2[j].v) leaf=e[i++];
		else leaf=e2[j++];
	//	if(leaf.v==-1) return ;
		int x=leaf.x,y=leaf.y;
		int fx=finds(x),fy=finds(y);
		if(fx==fy) continue;
		cnt+=leaf.v;
		if(cnt>=ans) return ;
		fa[fx]=fy;
		bian++;
	}
	ans=min(ans,cnt);
}
node cun[N];
void msort(int x,int l,int r){
	if(l==r) return ;
	int mid=l+r>>1;
	msort(x,l,mid),msort(x,mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[x][i].v<a[x][j].v) cun[k++]=a[x][i++];
		else cun[k++]=a[x][j++];
	}
	while(i<=mid) cun[k++]=a[x][i++];
	while(j<=r) cun[k++]=a[x][j++];
	for(int u=l;u<=r;u++) a[x][u]=cun[u];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i]={read(),read(),read()};
	}
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]={n+i+1,j,read()};
		}
		msort(i,1,n);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<(1<<k);i++){
		kruskal(i);
	}
	cout<<ans<<endl;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
	                    
