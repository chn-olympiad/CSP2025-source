#include<bits/stdc++.h>
const unsigned long long N=1e7;
unsigned long u[N],v[N],w[N];
using namespace std;
unsigned long sum;
bool vis[N];
struct node{
	int to1,to2,num;
}mp[N];
queue<unsigned long long>q;
void bfs(node x){
	q.push(x.to1);
	q.push(x.to2);
	while(!q.empty()){
		int t=q.front();
		if(vis[t]==0){
			q.push(mp[t].to1);
			vis[t]=1;
		}else{
			sum-=mp[t].num;
		}
		q.pop();
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		mp[i].to1=u[i];
		mp[i].to2=v[i];
		mp[i].num=w[i];
		sum+=w[i];
	}
	bfs(mp[1]);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}