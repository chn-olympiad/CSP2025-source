#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,k,tot,cnt,c[12],vis[12],tot1,K,al[12];
struct ill{
	int u,v,wei;
}qw[2010101<<1],q[10100],q1[12][10100];
ll ans,sum;
vector<int>to[11010];
bool cmp(ill a1,ill a2){
	return a1.wei<a2.wei;
}
int fa[201010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
//bool cmp1(ill a1,ill a2)
void krus(){
	cnt=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=0;i<=k;i++)al[i]=1;
	while(cnt<K-1){
		int id=1e9,minx=1e9;
		for(int i=0;i<=k;i++){
			if(!vis[i]||al[i]>n||(!i&&al[i]>=n))continue;
		//	cout<<q1[i][al[i]]
			if(minx>q1[i][al[i]].wei){
				minx=q1[i][al[i]].wei;
				id=i;
			}
		}
	//	cout<<cnt<<' '<<id<<' '<<' '<<al[id]<<endl;
		int x=q1[id][al[id]].u,y=q1[id][al[id]].v;
	//	cout<<x<<' '<<y<<' '<<q1[id][al[id]].wei<<endl;;
		if(find(x)!=find(y)){
			fa[fa[x]]=fa[y];
			cnt++;
			sum+=q1[id][al[id]].wei;
			if(sum>ans)return ;
		}al[id]++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		to[u].push_back(v);
		to[v].push_back(u);
		qw[i]=(ill){u,v,w};
	}stable_sort(qw+1,qw+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		int x=qw[i].u,y=qw[i].v;
		if(find(x)!=find(y)){
			ans+=qw[i].wei;
			fa[fa[x]]=fa[y];
			cnt++;
			q1[0][++tot]=qw[i];
		}
	}
	if(!k){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			q1[i][j]=(ill){i+n,j,x};
		}sort(q1[i]+1,q1[i]+1+n,cmp);
	}
	for(int i=1;i<(1<<k);i++){
		K=n;
		for(int j=1;j<=k;j++)vis[j]=0;sum=0;tot1=0;
		vis[0]=1;
	//	for(int j=1;j<=tot;j++)qw[++tot1]=q[j];
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				sum+=c[j];K++;vis[j]=1;
			//	for(int l=1;l<=n;l++)qw[++tot1]=q1[j][l];
			}
		}
		//stable_sort(qw+1,qw+1+tot1,cmp);
		krus();//cout<<"ok\n"<<endl;
		ans=min(ans,sum);
	}cout<<ans;
	return 0;
}

