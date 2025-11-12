#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int geshu[1000006];
int c[11];
int a[11][10004];
int you[11];
vector<int>road[1000006][3];
struct node{
	int x;
	int cost;
};
node q[10004];
int bfs(){
	int head=0;
	int end=1;
	q[head].x=1;
	while(head<end){
		node tmp=q[head];
		if(tmp.x==n){
			return tmp.cost;
		}
		head++;
		int tt=tmp.x;
		for(int i=0;i<geshu[tt];i++){
			if(road[tt][i][2]==0){
				q[head].x=road[tt][i][0];
				bool flag=false;
				for(int j=1;j<=k;j++){
					if(you[j]){
						if(road[tt][i][1]>=a[j][tt]+a[j][i]){
							flag=true;
							q[head].cost=tmp.cost+a[j][tt]+a[j][i];
						}						
					}else{
						if(road[tt][i][1]>=c[j]+a[j][tt]+a[j][i]){
							flag=true;
							q[head].cost=tmp.cost+c[j]+a[j][tt]+a[j][i];
							you[j]=1;
						}
					}
				}
				if(!flag){
					q[head].cost=tmp.cost+road[tt][i][1];
				}
				road[tmp.x][i][2]=1;
				end++;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		road[a][0].push_back(b);
		road[a][1].push_back(c);
		road[a][2].push_back(0);
		geshu[a]++;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	cout<<bfs();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
