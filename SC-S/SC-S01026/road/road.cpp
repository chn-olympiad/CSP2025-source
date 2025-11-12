#include<bits/stdc++.h>
using namespace std;
int ru[10050],rv[10050],rw[10050];
struct edge{
	int u,v,w,flag;
};
int ch[15][10050];
bool operator <(edge a,edge b){
	return a.w>b.w;
}
priority_queue<edge> q;
int f[10050];
int find(int x){
	if(x==f[x]) return x;
	f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
int n,m,k;
long long krs(){
	queue<edge> cun2;
	for(int i=1;i<=n+k;i++) f[i]=i;
	long long ans=0;
	while(!q.empty()){
		edge x=q.top();
		q.pop();
		cun2.push(x);
		int u=x.u,v=x.v,w=x.w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=w;
	}
	while(!cun2.empty()){
		edge x=cun2.front();
		cun2.pop();
		q.push(x);
	}
	return ans;
}
long long ans2=1e18;
void dfs(int x,long long sum){
	if(x==k){
		long long p=sum+krs();
		ans2=min(ans2,p);
		return;
	}
	for(int i=1;i<=n;i++){
		q.push({n+x+1,i,ch[x+1][i],x+1});
	}
	dfs(x+1,sum+ch[x+1][0]);
	queue<edge> cun;
	while(!q.empty()){
		edge xx=q.top();
		q.pop();
		if(xx.flag!=x+1) cun.push(xx);
	}
	while(!cun.empty()){
		edge xx=cun.front();
		cun.pop();
		q.push(xx);
	}
	dfs(x+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ru[i]>>rv[i]>>rw[i];
		q.push({ru[i],rv[i],rw[i],0});
	}
	int f1=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>ch[i][j];
			if(j==0&&ch[i][j]!=0) f1=0; 
		}
	}
	if(k==0){
		long long res=krs();
		cout<<res<<'\n';
		return 0;
	}
	if(f1){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				q.push({n+i,j,ch[i][j],0});
			}
		}
		long long res=krs();
		cout<<res<<'\n';
		return 0;
	}
	if(k<=10){
		dfs(0,0);
		cout<<ans2<<'\n';
	}
	return 0;
}