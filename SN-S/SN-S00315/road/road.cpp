#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,MOD=1e9+7,INF=1e18+7;
struct ed{
	int u,v,w;
}e[M],st[N];
struct ee{
	int v,w;
}a[11][N];
bool operator <(ed x,ed y){
	return x.w<y.w;
}
bool operator <(ee x,ee y){
	return x.w<y.w;
} 
int n,m,k,c[11],t[11],nw[11],fa[N],siz[N],top;
int findr(int x){
	if(fa[x]==x) return x;
	return fa[x]=findr(fa[x]);
}
void merge(int x,int y){
	if(siz[y]>siz[x]) swap(x,y);
	siz[x]+=siz[y];
	fa[y]=x;
}
//int fr[N],inv[N];
//int power(int x,int y){
//	int res=1;
//	while(y){
//		if(y&1) res=res*x%MOD;
//		x=x*x%MOD;
//		y>>=1;
//	}
//	return res;
//}
//int C(int x,int y){
//	if(x<y) return 0;
//	return fr[x]*inv[y]%MOD*inv[x-y]%MOD;
//}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		ch=getchar();
		if(ch=='-') f*=-1;
	}
	while(ch>='0' && ch<='9'){
		x*=10,x+=ch-48;
		ch=getchar();
	}
	return x*f;
}
signed main(){
//	system("fc club.out club5.ans");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	fr[0]=1;
//	for(int i=1;i<N;i++) fr[i]=fr[i-1]*i%MOD;
//	inv[N-1]=power(fr[N-1],MOD-2);
//	for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%MOD;
//	int n;cin>>n;
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		ans+=C(n,i)*i*10000;
//	}
//	cout<<ans;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int u=findr(e[i].u),v=findr(e[i].v);
		if(u==v) continue;
		st[++top].u=e[i].u,st[top].v=e[i].v,st[top].w=e[i].w;
		merge(u,v);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j].v=j,a[i][j].w=read();
		sort(a[i]+1,a[i]+n+1);
	}
//	cout<<"*";
	int ANS=INF;
	for(int s=0;s<(1<<k);s++){
//		cout<<s<<' ';
		int tot=0,ans=0;
		for(int j=0;j<k;j++) if(s&(1<<j)) t[++tot]=j+1,nw[j+1]=1,ans+=c[j+1];
		int cnt=n+tot;
		for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
		for(int i=1;i<=top;i++){
			for(int j=1;j<=tot;j++){
				int x=t[j];
				while(nw[x]<=n && a[x][nw[x]].w<=st[i].w){
//					cout<<nw[x]<<' ';
					int u=findr(a[x][nw[x]].v),v=findr(x+n);
					if(u==v) {nw[x]++;continue;}
					ans+=a[x][nw[x]].w;
					merge(u,v);
					cnt--;
					nw[x]++;
					if(cnt==1) break;
				}
				if(cnt==1) break;
			}
//			cout<<s<<' '<<cnt<<' '<<ans<<'\n';
			if(cnt==1) break;
			int u=findr(st[i].u),v=findr(st[i].v);
			if(u==v) continue;
			ans+=st[i].w;
			merge(u,v);
			cnt--;
			if(cnt==1) break;
		}
		ANS=min(ANS,ans);
//		if(s<=100) cout<<s<<' '<<ans<<'\n';
	}
	printf("%lld\n",ANS);
	return 0;
}
//15:45
