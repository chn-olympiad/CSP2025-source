#include<bits/stdc++.h>
using namespace std;
struct node{
	int to;int w;
};
vector<node>old_road[10005];
int new_road[10005][15],c[15];
int money[10005],flag[10005];
int n,m,k,ans;
queue<int>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		old_road[u].push_back({v,w});
		old_road[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>new_road[j][i];
		}
	}
	q.push(1);
	flag[1]=1;
	for(int i=2;i<=n;i++){
		money[i]=1e9;
	}
	while(q.size()){
		int nowdis=q.front();
		//cout<<nowdis<<endl;
		for(int i=0;i<old_road[nowdis].size();i++){
			int willdis=old_road[nowdis][i].to;
			//cout<<willdis<<endl;
			if(money[willdis]>money[nowdis]+old_road[nowdis][i].w){
				money[willdis]=money[nowdis]+old_road[nowdis][i].w;
				q.push(willdis);
				if(flag[willdis]==0){
					flag[willdis]++;
					ans+=old_road[nowdis][i].w;
				}
			}
		}
		q.pop();
	}
	cout<<ans;
	return 0;
}
