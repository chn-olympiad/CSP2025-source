#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > w(10004),u(10004);
int n,m,k;
int ans=0,sum=0;
bool flag[10004];
void dfs(int dqjd,int step){
	if(step==n){
		ans=max(ans,sum);
		return ;
	}
	if(flag[dqjd]==true){
		return ;
	}
	flag[dqjd]=true;
		for(int i=0;i<u[dqjd].size();i++){
			sum+=w[dqjd][i];
			dfs(u[dqjd][i],step+1);
			sum-=w[dqjd][i];
		}
	flag[dqjd]=false;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int uu,ww,vv;
	for(int i=1;i<=m;i++){
		cin>>uu>>vv>>ww;
		w[i].push_back(ww);
		u[uu].push_back(vv);
		u[vv].push_back(uu);
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}

