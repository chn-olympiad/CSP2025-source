#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> >vec[10005];
int a[12][10005];
int num;
int sum;
int vis[10005];
priority_queue<pair<int,int> >pq;
void bfs(){
	while(pq.size()){
		if(num==n){
			return ;
		} 
		int pos=pq.top().second;
		sum-=pq.top().first;
		pq.pop();
//		cout<<pos<<endl;
		for(int i=0;i<vec[pos].size();i++){
			int v=vec[pos][i].first;
			if(!vis[v]&&v<=n){
				vis[v]=1;
				pq.push(make_pair(-vec[pos][i].second,v));
			}
		}
		num++;
//		cout<<endl;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		vec[u].push_back(make_pair(v,w));
		vec[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&a[j][i]);
			if(j==0){
				continue;
			}
			vec[n+i].push_back(make_pair(j,a[j][i]));
			vec[j].push_back(make_pair(n+i,a[j][i]));
		}
	}
	pq.push(make_pair(0,1)); 
	bfs();
	printf("%d",sum);
	return 0;
} 
