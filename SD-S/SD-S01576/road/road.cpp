#include<bits/stdc++.h>
using namespace std;
int n,m,k,head[100005],ecnt,x,y,z,vis[100005],fee[15][10005],ww[15],fl=1;
long long ans,sum;
struct nod{
	int next,to,w;
}a[3000005];//
struct node{
	int u;
	long long w;
	int fro;
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
struct no{
	int u,v,w;
}bi[1000005];
priority_queue<node> q;
void pri(){
	q.push({1,0,0});
	while(!q.empty()){
		int u=q.top().u,fro=q.top().fro;
		long long w=q.top().w;
		q.pop();
		if(vis[u]){
			continue;
		}
//		cout<<"!"<<u<<" "<<fro<<" "<<w<<endl;
		vis[u]=1;
		sum+=w;
		for(int i=head[u];i;i=a[i].next){
			q.push({a[i].to,a[i].w,u});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		bi[i]={x,y,z};
		a[++ecnt]={head[x],y,z};
		head[x]=ecnt;
		a[++ecnt]={head[y],x,z};
		head[y]=ecnt;
	}
	for(int i=1;i<=k;i++){
		cin>>ww[i];
		if(ww[i]!=0){
			fl=0;
		}
		for(int j=1;j<=n;j++){
			cin>>fee[i][j];
		}
	}
	if(k==0){
		pri();
		cout<<sum;
		return 0;
	}
	if(k<=5){
		pri();
		ans=sum;
		for(int i=1;i<(1<<k);i++){
			cout<<i<<endl;
			ecnt=0;
			for(int j=1;j<=n+k;j++){
				head[j]=0;
				vis[j]=0;
			}
			for(int j=1;j<=m;j++){
				int u=bi[j].u,v=bi[j].v,w=bi[j].w;
//				cout<<u<<" "<<v<<" "<<w<<endl;
				a[++ecnt]={head[u],v,w};
				head[u]=ecnt;
				a[++ecnt]={head[v],u,w};
				head[v]=ecnt;
			}
			sum=0;
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					sum+=ww[j+1];
					for(int l=1;l<=n;l++){
						int u=j+1,v=l,w=fee[u][v];
						a[++ecnt]={head[u+n],v,w};
						head[u+n]=ecnt;
						a[++ecnt]={head[v],u+n,w};
						head[v]=ecnt;
//						cout<<u<<" "<<v<<" "<<w<<endl;
					}
				}
			}
//			cout<<sum<<endl;
			pri();
//			cout<<sum<<endl;
			ans=min(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

