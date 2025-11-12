#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+10;
LL n,m,k,cnt,f[N],p,vis[N],sum,ans,mins=1e18;
int c[20][10100];
struct Eb{LL x,y,w;}e[N],E[N];
LL Find(LL k){
	if(f[k]!=k) f[k]=Find(f[k]);
	return f[k];
}
bool cmp(Eb i,Eb j){
	return ((i.w<j.w)||(i.w==j.w&&i.x==0));
}
void check(){
	LL sum=0,Ans=0,Last=0,tot=0;
//	cout<<p<<" "<<cnt<<"\n";
	if(p!=n) p++;
	for(int i=1;i<=cnt;i++){
		if(e[i].x==0) tot++,E[tot].x=e[i].x,E[tot].y=e[i].y,E[tot].w=e[i].w,Last++;
	} 
	for(int i=1;i<=cnt;i++){
		if(e[i].x!=0) tot++,E[tot].x=e[i].x,E[tot].y=e[i].y,E[tot].w=e[i].w;
	}
	sort(E+Last+1,E+cnt+1,cmp);
	for(int i=0;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=cnt;i++){
		LL a=Find(E[i].x),b=Find(E[i].y);
		if(a!=b){f[a]=b;sum++;Ans+=E[i].w;} 
		if(sum==p-1){mins=min(mins,Ans);return;}
	}
//	cout<<sum<<" "<<p-1<<"\n";
}
void dfs(LL X){
	if(X==k+1){
		check();
		if(p-1!=n) p--;
	} 
	else{
		//加点 
		p++;
		for(int i=0;i<=n;i++){
			cnt++;
			e[cnt].x=i,e[cnt].y=X+n,e[cnt].w=c[X][i];
		}
		dfs(X+1);
		cnt-=(n+1);p--;
		//不加点 
		dfs(X+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].w;
	cnt=m;
	if(m<100000){
		for(int i=1;i<=k;i++){
			cin>>c[i][0];
			for(int j=1;j<=n;j++){
				cin>>c[i][j];
			}
		}
		p=n;
		dfs(1);
		cout<<mins;
	}else{
		for(int i=1;i<=k;i++){
			cnt++;
			cin>>e[cnt].w;
			e[cnt].x=0,e[cnt].y=n+i;
			for(int j=1;j<=n;j++){
				cnt++;
				cin>>e[cnt].w;
				e[cnt].x=j,e[cnt].y=n+i;
			}
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=0;i<=n+k;i++) f[i]=i;
		p=n;
		for(int i=1;i<=cnt;i++){
			LL a=Find(e[i].x),b=Find(e[i].y);
			if(a!=b){
				if(e[i].y>n&&vis[e[i].y]==0&&e[i].x!=0) continue;
	//			cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<"\n";
				f[a]=b;
				if(e[i].x==0&&vis[0]==0) vis[0]=1,p++;
				if(e[i].y>n&&vis[e[i].y]==0) vis[e[i].y]=1,p++;
				sum++;ans+=e[i].w;
			} 
			if(sum==p-1){cout<<ans;return 0;}
		}
	}
	return 0;
}
