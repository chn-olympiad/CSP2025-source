#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+10,M=2e6+10;
int f[N],U[M],V[M],W[M],n,m,id[M],k,c[12][N],U2[M],V2[M],W2[M];
int find(int u) {
	if(f[u]!=u) f[u]=find(f[u]);
	return f[u];
}
void add(int u,int v,int w) {
	U[++m]=u,V[m]=v,W[m]=w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;

	for(int i=1; i<=m; i++) cin>>U[i]>>V[i]>>W[i],U2[i]=U[i],V2[i]=V[i],W2[i]=W[i];
	bool fl=0;
	for(int i=1; i<=k; i++) {
		cin>>c[i][0];
		fl|=(c[i][0]!=0);
		for(int j=1; j<=n; j++) cin>>c[i][j];
	}
	if(!fl) {
		for(int i=1; i<=n+k; i++) f[i]=i;
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) add(i+n,j,c[i][j]+c[i][0]);
		}
		for(int i=1; i<=m; i++) id[i]=i;
		sort(id+1,id+m+1,[](int a,int b)->bool {return W[a]<W[b];});
		int ans=0;
		for(int qi=1; qi<=m; qi++) {
			int i=id[qi];
			if(find(U[i])==find(V[i])) continue;
			ans+=W[i];
			f[find(U[i])]=find(V[i]);
		}
		cout<<ans;

		return 0;
	}
	int U=(1<<k)-1,t=m,Ans=1e9;
	for(int s=0; s<=U; s++) {
		for(int i=1; i<=n+k; i++) f[i]=i;
		m=t;
		for(int i=1; i<=m; i++) ::U[i]=U2[i],V[i]=V2[i],W[i]=W2[i];
		int ans=0;
		for(int i=0; i<k; i++)if(s&(1<<i)) {
				ans+=c[i+1][0];
				for(int j=1; j<=n; j++) add(i+n+1,j,c[i+1][j]);
			}
		for(int i=1; i<=m; i++) id[i]=i;
		sort(id+1,id+m+1,[](int a,int b)->bool {return W[a]<W[b];});

		for(int qi=1; qi<=m; qi++) {
			int i=id[qi];
			if(find(::U[i])==find(V[i])) continue;
			ans+=W[i];
			f[find(::U[i])]=find(V[i]);
		}
//		cout<<s<<' '<<ans<<endl;
		Ans=min(Ans,ans);
	}
	cout<<Ans;

	return 0;
}
/*

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+10,M=2e6+10;
int f[N],U[M],V[M],W[M],n,m,id[M],k,c[12][N];
int find(int u){
	if(f[u]!=u) f[u]=find(f[u]);
	return f[u];
}
void add(int u,int v,int w){
	U[++m]=u,V[m]=v,W[m]=w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>U[i]>>V[i]>>W[i];
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++) cin>>c[i][j],add(i+n,j,c[i][j]+c[i][0]);
	}
	for(int i=1;i<=m;i++) id[i]=i;
	sort(id+1,id+m+1,[](int a,int b)->bool{return W[a]<W[b];});
	int ans=0;
	for(int qi=1;qi<=m;qi++){
		int i=id[qi];
		if(find(U[i])==find(V[i])) continue;
		ans+=W[i];
		f[find(U[i])]=find(V[i]);
	}
	cout<<ans;

	return 0;
}

*/
