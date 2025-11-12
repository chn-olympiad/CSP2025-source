#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cost[15][10005],c[15],mins[10005],fa[10005],cs[15],ans=1e9;
struct Node{
	int u,v,w;
}G[1100006],H[1100006];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dg(int x){
	if(x==k+1){
		for(int i=1;i<=m;i++){
			H[i].u=G[i].u,H[i].v=G[i].v,H[i].w=G[i].w;
		}
		int pos=m,N=n,co=0,cc=0;
		for(int i=1;i<=k;i++){
			if(c[i]){
				//cout<<"choose: "<<i<<endl;
				co+=cs[i];
				N++;
				for(int j=1;j<=n;j++){
					H[++pos].w=cost[i][j];
					H[pos].u=N;
					H[pos].v=j;
				}
			}
		}
		for(int i=1;i<=N;i++)fa[i]=i;
		sort(H+1,H+pos+1,cmp);
//		for(int i=1;i<=pos;i++){
//			cout<<H[i].u<<" "<<H[i].v<<" "<<H[i].w<<endl;
//		}
		for(int i=1;i<=pos;i++){
			int u=H[i].u,v=H[i].v;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;
			cc++;
			fa[fu]=fv;
			co+=H[i].w;
			if(cc==N-1)break;
		}
		ans=min(ans,co);
		//cout<<co<<endl;
		//cout<<"******\n";
		return ;
	}
	for(c[x]=0;c[x]<=1;c[x]++){
		dg(x+1);
	}
}
void dg2(int x){
	for(int i=1;i<=k;i++)c[i]=0;
	if(1){
		for(int i=1;i<=m;i++){
			H[i].u=G[i].u,H[i].v=G[i].v,H[i].w=G[i].w;
		}
		int pos=m,N=n,co=0,cc=0;
		for(int i=1;i<=k;i++){
			if(c[i]){
				//cout<<"choose: "<<i<<endl;
				co+=cs[i];
				N++;
				for(int j=1;j<=n;j++){
					H[++pos].w=cost[i][j];
					H[pos].u=N;
					H[pos].v=j;
				}
			}
		}
		for(int i=1;i<=N;i++)fa[i]=i;
		sort(H+1,H+pos+1,cmp);
//		for(int i=1;i<=pos;i++){
//			cout<<H[i].u<<" "<<H[i].v<<" "<<H[i].w<<endl;
//		}
		for(int i=1;i<=pos;i++){
			int u=H[i].u,v=H[i].v;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;
			cc++;
			fa[fu]=fv;
			co+=H[i].w;
			if(cc==N-1)break;
		}
		ans=min(ans,co);
		//cout<<co<<endl;
		//cout<<"******\n";
		//return ;
	}
	for(int i=1;i<=k;i++)c[i]=1;
	if(1){
		for(int i=1;i<=m;i++){
			H[i].u=G[i].u,H[i].v=G[i].v,H[i].w=G[i].w;
		}
		int pos=m,N=n,co=0,cc=0;
		for(int i=1;i<=k;i++){
			if(c[i]){
				//cout<<"choose: "<<i<<endl;
				co+=cs[i];
				N++;
				for(int j=1;j<=n;j++){
					H[++pos].w=cost[i][j];
					H[pos].u=N;
					H[pos].v=j;
				}
			}
		}
		for(int i=1;i<=N;i++)fa[i]=i;
		sort(H+1,H+pos+1,cmp);
//		for(int i=1;i<=pos;i++){
//			cout<<H[i].u<<" "<<H[i].v<<" "<<H[i].w<<endl;
//		}
		for(int i=1;i<=pos;i++){
			int u=H[i].u,v=H[i].v;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;
			cc++;
			fa[fu]=fv;
			co+=H[i].w;
			if(cc==N-1)break;
		}
		ans=min(ans,co);
		//cout<<co<<endl;
		//cout<<"******\n";
		//return ;
	}
}
signed main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	bool flag=1;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[i].u=u,G[i].v=v,G[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>cs[i];
		if(cs[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
		}
	}
	if(m<=100000||k==0)flag=0;
	if(!flag){
		dg(1);
		cout<<ans;
	}
	else{
		dg2(1);
		cout<<ans;
	}
	return 0;
}
