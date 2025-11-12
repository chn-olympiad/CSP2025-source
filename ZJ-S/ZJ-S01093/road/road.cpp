#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,c;
	bool operator <(edge w)const{
		return u<w.u;
	}
};
vector<int> f;
int gf(int n){
	return n==f[n]?n:f[n]=gf(f[n]);
}
void meg(int a,int b){
	f[gf(a)]=gf(b);
}
bool same(int a,int b){
	return gf(a)==gf(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	f.resize(n+k+1);
	for(int i=1;i<=n;i++) f[i]=i;
	vector<edge> e(m);
	vector<vector<int>> s(k,vector<int>(n+1));
	vector<vector<bool>> vis(k,vector<bool>(n+1));
	for(edge &i:e) cin>>i.u>>i.v>>i.c;
	for(int i=0;i<k;i++)
		for(int j=1;j<=n;j++)
			cin>>s[i][j];
	for(edge &i:e)
		for(int j=0;j<k;j++)
			i.c=min(i.c,s[j][i.u]+s[j][i.v]);
	sort(e.begin(),e.end());
	int i=0;
	for(edge i:e){
		if(!same(i.u,i.v)){
			ans+=i.c;
			meg(i.u,i.v);
		}
	}
	cout<<ans;
}