#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;

struct node{
	int x,y,w;
}e[1500005];


int a[14][100005];

int to[11][100005];

inline bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[100005];
inline int find(int x){
	if (fa[x]!=x)return fa[x]=find(fa[x]);
	return fa[x];
}
inline int kruskal(){
	int ans=0;
	int cnt=0;
	
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	for (int i=1;i<=m;i++){
		int x=find(e[i].x);
		int y=find(e[i].y);
		int w=e[i].w;
		if (x!=y){
			ans+=w;
			cnt++;
			if (cnt==n-1){
				break;
			}
			fa[x]=y;
		}
	}
	return ans;
}

int R[105];

inline int kru(){
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	int res=0;
	int cnt=0;
	for (int i=1;i<=m;i++){
		int x=find(e[i].x);
		int y=find(e[i].y);
		int w=e[i].w;
		if (x!=y){
			int temp=0;
			for (int j=1;j<=k;j++){
				if (w>to[j][x]+to[j][y]){
					w=to[j][x]+to[j][y];
					temp=j;
				}
			}
			R[temp]=1;
			fa[x]=y;
			cnt++;
			res+=w;
			if (cnt==n-1){
				break;
			}
			for (int j=1;j<=k;j++){
				to[j][y]=min(to[j][x],to[j][y]);
			}
		}
	}
	return res;
}


int ans=1e18;


int vis[15];

inline int K(){
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	int res=0;
	int cnt=0;
	for (int i=1;i<=m;i++){
		int x=find(e[i].x);
		int y=find(e[i].y);
		int w=e[i].w;
		if (x!=y){
			for (int j=1;j<=k;j++){
				if (vis[j]){
					w=min(w,to[j][x]+to[j][y]);
				}
			}
			fa[x]=y;
			cnt++;
			res+=w;
			if (cnt==n-1){
				break;
			}
			for (int j=1;j<=k;j++){
				to[j][y]=min(to[j][x],to[j][y]);
			}
		}
	}
	return res;
}


inline void dfs(int x){
	if (clock()>=985){
		cout<<ans;
		exit(0);
	}
	if (x==k+1){
		int cnt=0;
		for (int i=1;i<=k;i++){
			if (vis[i]){
				cnt+=a[i][0];
				for (int j=1;j<=n;j++){
					to[i][j]=a[i][j];
				}
			}
		}
		if (cnt>ans){
			return;
		}
		ans=min(ans,K()+cnt);
		return;
	}
	if (rand()%3==1){
		vis[x]=1;
		dfs(x+1);
		vis[x]=0;
		dfs(x+1);	
	}
	else{
		vis[x]=0;
		dfs(x+1);	
		vis[x]=1;
		dfs(x+1);
	}
	
}


signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	for (int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if (k==0){
		cout<<kruskal();
		return 0;
	}
	ans=kruskal();
	int cnt=0;
	for (int i=1;i<=k;i++){
		cnt+=a[i][0];
		for (int j=1;j<=n;j++){
			to[i][j]=a[i][j];
		}
	}
	int bt=kru();
	for (int i=1;i<=k;i++){
		if (!R[i]){
			bt-=a[i][0];
		}
	}
	ans=min(ans,bt+cnt);
	dfs(1);
	cout<<ans;
	return 0;
}
