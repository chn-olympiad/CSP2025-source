#include<bits/stdc++.h>
using namespace std;
struct nd{
	int to;
	int w;
	operator < (const nd &q)const{
		return w>q.w;
	}
};
int n,m,k;
vector<nd>v[100001];
int vis[1000001];
priority_queue<nd>q;
int ans;
int nn[10001][10001];
int cs[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=0;i<m;i++){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			v[aa].push_back({bb,cc});
			v[bb].push_back({aa,cc});
		}
	}
	else{
		for(int i=0;i<m;i++){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			if(nn[aa][bb]==0){
				nn[aa][bb]=cc;
				nn[bb][aa]=cc;
			}
			else{
				nn[aa][bb]=min(nn[aa][bb],cc);
				nn[bb][aa]=min(nn[bb][aa],cc);
			}
		}
		for(int i=1;i<=k;i++){
			int nw=0;
			for(int j=1;j<=n;j++){
				cin>>cs[j];
				if(cs[j]==0){
					nw=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(j==nw){
					continue;
				}
				if(nn[nw][j]==0){
					nn[nw][j]=cs[j];
					nn[j][nw]=cs[j];
				}
				else{
					nn[nw][j]=min(nn[nw][j],cs[j]);
					nn[j][nw]=min(nn[j][nw],cs[j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(nn[i][j]!=0){
					v[i].push({j,n[i][j]});
				}
			}
		}
	}
	q.push({1,0});
	while(!q.empty()){
		nd d=q.top();
		q.pop();
		if(vis[d.to]){
			continue;
		}
		vis[d.to]=1;
		ans+=d.w;
		for(int i=0;i<v[d.to].size();i++){
			q.push({v[d.to][i].to,v[d.to][i].w});
		}
	}
	cout<<ans;
}
