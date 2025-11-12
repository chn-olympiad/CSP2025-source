#include<bits/stdc++.h>
using namespace std;
struct data1{
	int to,w;
};
vector<data1>a[10005];
struct data2{
	int x,w;
	bool operator<(const data2 &b)const{
		return b.w<w;
	}
};
priority_queue<data2>q;
int n,m,k,u,v,w,x,c[10005];
bool f[10005];
long long ans=0,dis[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=2;i<=n;i++){
		dis[i]=2e9;
		f[i]=0;
	}
	for(int j=1;j<=k;j++){
		cin>>x;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]==0){
				x=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(x!=i){
				a[x].push_back({i,c[i]});
				a[i].push_back({x,c[i]});
				
			}
		}
	}
	dis[1]=0;
	q.push({1,0});
	for(int i=1;i<=n;i++){
		while(f[q.top().x]!=0)q.pop();
		k=q.top().x;
		ans+=q.top().w;
		q.pop();
		f[k]=1;
		for(int j=0;j<a[k].size();j++){
			if(a[k][j].w<dis[a[k][j].to]&&f[a[k][j].to]==0){
				dis[j]=a[k][j].w;
				q.push({a[k][j].to,a[k][j].w});
			}
		}
		//cout<<ans;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3 0
1 2 1
2 3 1
1 3 2
*/
