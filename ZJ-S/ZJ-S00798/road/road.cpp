#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long> > >,greater<pair<long long,pair<long long,long long> > > > q;
long long n,m,k,f[100010],e[100010],ans,x,y,z,b[100010];
struct no{
	int x,y,z;
}a[100010];
long long find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool cmp(no q,no h){
	return q.z<h.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++) f[i]=i,e[i]=1;
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			long long fx=find(a[i].x);int fy=find(a[i].y);
			if(fx!=fy){
				ans+=a[i].z;
				f[fy]=fx;
				e[fx]+=e[fy];
			}
			if(e[fx]==n){
				cout<<ans;
				return 0;
			}
		}
	}
	for(int i=1;i<=m;i++) cin>>x>>y>>z,q.push({z,{x,y}});
	for(int i=1;i<=k;i++){
		long long x;
		cin>>x;
		for(int j=1;j<=n;j++) cin>>b[j];
		for(int j=1;j<n;j++)
			for(int k=j+1;k<=n;k++){
				q.push({x+b[j]+b[k],{j,k}});
			}
	}
	for(int i=1;i<=n;i++) f[i]=i,e[i]=1;
	while(!q.empty()){
		long long fx=find(q.top().second.first);long long fy=find(q.top().second.second);
		long long z=q.top().first;
		q.pop();
		if(fx!=fy){
			ans+=z;
			f[fy]=fx;
			e[fx]+=e[fy];
		}
		if(e[fx]==n){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
