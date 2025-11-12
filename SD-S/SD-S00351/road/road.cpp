#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int N=2e6+10,M=5e4+10;
struct node{
	int to,w;
};
vector <node> G[M];
int fzj[110][M];
int n,m,k;
struct bian{
	int u,v;int w;
}a[N];
int atop;
int f[M];
bool cmp(bian a,bian b){
	return a.w<b.w;
}
int findf(int k){
	if(f[k]==k) return k;
	else return f[k]=findf(f[k]);
}
int klz(bian b[],int btop,int sd){
	int ans=0;
	sort(b+1,b+btop+1,cmp);
	for(int i=1;i<=sd;i++) f[i]=i;
	for(int i=1;i<=btop;i++){
		int fu=findf(b[i].u),fv=findf(b[i].v);
		if(fu==fv) continue;
		f[fu]=fv;
		ans+=b[i].w;
	} 
	return ans;
}
struct wkj{
	int a,b;
}ww[N];
bool cmp2(wkj a,wkj b){
	return a.b<b.b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
		a[++atop]={u,v,w};
	}
	int ans=klz(a,atop,n);
	//cout<<"wzk\n";
//	cout<<<<"\n";
//	cout<<"fzj\n";
	for(int i=1;i<=k;i++){
		atop=m;
	//	cout<<"cnm:"<<i<<"\n";
		for(int j=0;j<=n;j++){
		//	cout<<j<<" ";
			cin>>fzj[i][j];
			//n+i
			if(j) a[++atop]={n+i,j,fzj[i][j]};
		}
		//cout<<"frbug2:"<<"\n";
		ww[i]={i,klz(a,atop,n+k)+fzj[i][0]};
	}
	//cout<<"114514\n";
	sort(ww+1,ww+k+1,cmp2);
	atop=m;
	for(int u=1;u<=k;u++){
		atop=m;
		for(int j=1;j<=n;j++){
			a[++atop]={n+ww[u].a,j,fzj[ww[u].a][j]};
		}
		int now=atop;
		int anss=ww[u].b;
		for(int i=1;i<=k;i++){
			if(k==u) continue;
			atop=now;
			for(int j=1;j<=n;j++){
				a[++atop]={n+ww[i].a,j,fzj[ww[i].a][j]};
			}
			int ewr=klz(a,atop,n+k)+fzj[ww[i].a][0];
			if(ewr<anss){
				anss=ewr;
				now=atop;
			}
		}
		ans=min(ans,anss);
	}
	cout<<ans<<"\n";
	return 0;
}

