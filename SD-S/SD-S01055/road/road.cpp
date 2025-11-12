#include <bits/stdc++.h>
#define For(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
using namespace std;
typedef long long ll;
const int M=1e6+5,N=1e4+100,K=15;
const ll I=2e17+5;
int n,m,k,f[N],cnt,xf[N],cnt2;
struct edge{
	int u,v,w;
	friend bool operator<(const edge &a,const edge &b){
		return a.w<b.w; 
	}
}ew[M],e[M],etr[M];
struct edge2{
	int v,w;
	friend bool operator<(const edge2 &a,const edge2 &b){
		return a.w<b.w;
	}
}fu[K][N];
ll ans=I,sum;
int get(int x){
	if(x==f[x]) return x;
	return f[x]=get(f[x]);
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	For(i,1,m) ew[i].u=read(),ew[i].v=read(),ew[i].w=read();
	For(i,1,k){
		xf[i]=read();
		For(j,1,n){
			fu[i][j].v=j;
			fu[i][j].w=read();
		}
		sort(fu[i]+1,fu[i]+n+1);
	}
	sort(ew+1,ew+m+1);
	For(i,1,n) f[i]=i;
	For(i,1,m){
		if(get(ew[i].u)==get(ew[i].v)) continue;
		f[get(ew[i].v)]=get(ew[i].u);
		e[++cnt]=ew[i];
		sum+=ew[i].w;
	}
	For(op,0,(1<<k)-1){
		sum=cnt2=0ll;
		For(i,1,cnt) ew[++cnt2]=e[i];
		For(i,1,n+k) f[i]=i;
		For(i,1,k) if((op>>(i-1))&1){
			sum+=1ll*xf[i];
			int u=1,v=1,len=0;
			while(len<cnt2+n){
				while(u<=cnt2&&(ew[u].w<=fu[i][v].w||v>n)) etr[++len]=ew[u++];
				while(v<=n&&(ew[u].w>=fu[i][v].w||u>cnt2))
					etr[++len]={n+i,fu[i][v].v,fu[i][v++].w};
			}
			cnt2+=n;
			For(i,1,cnt2) ew[i]=etr[i];
		}
		sort(ew+1,ew+cnt2+1);
		For(i,1,cnt2){
			if(get(ew[i].u)==get(ew[i].v)) continue;
			f[get(ew[i].v)]=get(ew[i].u);
			sum+=1ll*ew[i].w;
		}
		ans=min(ans,sum);
	}
	write(ans);
	return 0;
}
