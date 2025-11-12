#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[15][10005],c[15];
long long ans;
long long w,minn;
bool inq[1000005],iq[15];
queue<int>Q;
struct node{
	int to;
	long long w;
};
vector<node>V[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		V[u].push_back((node){v,w});
		V[v].push_back((node){u,w});
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];//xiang zhen j
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	inq[1]=1;
	int nk=1;
	while(nk<n){
		minn=2e9+10;
		int x,y=0;
		for(int u=1;u<=n;u++){
			if(!inq[u]) continue;
			int len=V[u].size();
			for(int i=0;i<len;i++){
				int v=V[u][i].to,w=V[u][i].w;
				if(inq[v]) continue;
				if(w<minn){
					minn=w;
					x=v;
				}
			}
			for(int i=1;i<=n;i++){
				if(inq[i]) continue;
				for(int j=1;j<=k;j++){
					w=a[j][u]+a[j][i];
					if(!iq[j]) w+=c[j];
					if(w<minn){
						minn=w;
						x=i;
						y=j;
					}
				}
			}
		}
		ans+=minn;
		Q.push(x);
		inq[x]=1;
		if(y) iq[y]=1;
		nk++;
	}
	cout<<ans<<endl;
	return 0;
}
