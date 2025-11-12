#include<bits/stdc++.h>
using namespace std;
#define int long long
#define R read()
inline int read(){
	int re=0;
	char ch;
	while (1){
		ch=getchar();
		if ('0'<=ch and ch<='9')	break;
	}
	while (1){
		re=re*10+ch-'0';
		ch=getchar();
		if ('0'>ch or ch>'9')	return re;
	}
}
const int N=1e4+50,M=1e6+50,K=11;
int flag[N];
struct ge{
	int from,to,val;
}e[(N*K+M)<<1],e2[N*K*2+M*2];
int n,m,k,cnt;
int head[N];
int h[N];
int ans;
int f[K];
int siz[K][N];
int cs,cn;
int mi;
int co[N];
int t;
inline void addedge(int x,int y,int v){
	e[++cnt]={x,y,v};
	head[x]=cnt;
}
bool cmp(ge x,ge y){
	return x.val<y.val;
}
int w[N];
inline void zxscs(int x){
//	cout<<x<<" ";
	if (x==k){
		memset(w,0,sizeof(w));
		n=cn,mi=0,cnt=cs;
		for (int i=1;i<=k;i++)
			if (f[i]){
				mi+=co[i];
				n++;
				for (int j=1;j<=cn;j++){
					addedge(j,n,siz[i][j]);
					addedge(n,j,siz[i][j]);
				}
			}	
		for (int i=1;i<=cnt;i++)	e2[i]=e[i];
		sort(e2+1,e2+cnt+1,cmp);
		for (int i=1;i<=n;i++)	flag[i]=i,w[i]=0;
		for (int i=1;i<=cnt;i++){
			int from=e2[i].from,to=e2[i].to,val=e2[i].val;
			if (flag[from]!=flag[to]){
				int k=flag[from];
				for (int i=1;i<=n;i++)
					if (flag[i]==k)	flag[i]=flag[to],w[to]++;
				mi+=val;
//				cout<<from<<" "<<to<<"\n";
			}
			if (w[to]==n)	break;
		}
		ans=min(mi,ans);
//		cout<<mi<<" "<<ans<<"\n";
//		cout<<t<<" ";
		return ;
	}
	f[x+1]=1;
	zxscs(x+1);
	f[x+1]=0;
	zxscs(x+1); 
}
signed main(){
	ans=1145141919810;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		int x,y,v;
		x=read(),y=read(),v=read();
		addedge(x,y,v);
		addedge(y,x,v);
	}
	for (int i=1;i<=k;i++){
		co[i]=read();
		for (int j=1;j<=n;j++)	siz[i][j]=read();
	}
	if (k<=5){
		for (int i=1;i<=n;i++)	h[i]=head[i];
		cs=cnt;
		cn=n;
		zxscs(0);
		cout<<ans;
	}
	else{
		int wow=0;
		for (int i=1;i<=k;i++){
			wow+=co[i];
			for (int j=1;j<=n;j++){
				addedge(n+i,j,siz[i][j]);
				addedge(j,n+i,siz[i][j]);
			}
		}
		n+=10;
		for (int i=1;i<=n;i++)	h[i]=head[i];
		k=0;
		cs=cnt;
		cn=n;
		zxscs(0);
		cout<<ans;
	}
}
//搜2^10次最小生成树？ 
