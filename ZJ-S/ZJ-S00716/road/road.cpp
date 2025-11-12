#include<bits/stdc++.h>
using namespace std;
#define inf 1000000009
#define ll long long

struct node{
	int vst;
	ll wei;
};

struct usp{
	int u,v;
	ll w;
};

vector <node> t[10005];
int f[10005];
ll a[10005][15],c[10005];
ll M[10005][10005];
usp p[10005];

int n,m,k;

int cmp(usp x,usp y){
	return x.w<y.w;
}

int getfather(int x){
	if(f[x]==x)return x;
	return getfather(f[x]);
}

void bc_fa(int x,int fa){
	f[getfather(x)]=getfather(fa);
//	f[x]=fa;
}

void bl(){
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	sort(p+1,p+1+m,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=p[i].u,v=p[i].v;
		ll w=p[i].w;
		
		if(getfather(u)==getfather(v))continue;
		else{
			
			node l;
			
			l.vst=v,l.wei=w;
			t[u].push_back(l);
			
			l.vst=u;
			t[v].push_back(l);
			
			bc_fa(u,v);
			
			ans+=w;
			
		}
	}
	cout<<ans<<endl;
}

void bl_k(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			M[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		M[u][v]=w;
		M[v][u]=w;
		
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			for(int h=1;h<j;h++){
				ll all=a[h][i]+a[j][i]+c[i];
				M[h][j]=M[j][h]=min(M[j][h],all);
			}
		}
	}
	int cnt2=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(M[i][j]!=inf){
			//	cout<<i<<' '<<j<<endl;
				p[++cnt2].u=i;
				p[cnt2].v=j;
				p[cnt2].w=M[i][j];
			}
		}
	}
//	for(int i=1;i<=cnt2;i++){
//		cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].w<<endl;
//	}
	sort(p+1,p+1+cnt2,cmp);
	ll ans=0;
	
	for(int i=1;i<=cnt2;i++){
		int u=p[i].u,v=p[i].v;
		ll w=p[i].w;
		
		if(getfather(u)==getfather(v))continue;
		else{
			
			node l;
			
			l.vst=v,l.wei=w;
			t[u].push_back(l);
			
			l.vst=u;
			t[v].push_back(l);
			
			bc_fa(u,v);
			
			ans+=w;
			
		}
	}
	cout<<ans<<endl;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	if(k==0){
		bl();
	}
	else{
		bl_k();
	}
}
