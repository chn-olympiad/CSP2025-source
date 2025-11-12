#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],fa[10005],a[15][10005];
struct node{
	long long u,v,w;
	friend bool operator<(const node& a,const node& b){
		return a.w<b.w;
	}
};
long long find(long long x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
} 
vector<node> ed(2000025);
void solve(){
	long long sum=0;
	long long o=1;
	sort(ed.begin(),ed.end());
	for(auto a:ed){
		if(o==n) break;
		if(find(a.u)==find(a.v))
			continue;
		o++;
		fa[a.u]=fa[a.v];
		sum+=a.w;
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)
		fa[i]=i;
	long long u,v,w;
	for(long long i=1;i<=m;i++){
		cin>>u>>v>>w;
		ed.push_back({u,v,w});
		ed.push_back({v,u,w});
	}
	if(k==0){
		solve();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++)
			cin>>a[i][j];
		for(long long j=1;j<=n-1;j++)
			for(long long p=j+1;p<=n;p++){
				ed.push_back({j,p,a[i][j]+a[i][p]});
				ed.push_back({p,j,a[i][j]+a[i][p]});
			}
	}
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
