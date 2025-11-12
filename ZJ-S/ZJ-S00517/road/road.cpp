#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> G1[150100],G2[150100];
int ans,n,m,k,i,b[15][100100],j;
bool vis[100100];
struct Node{
	int u,v,w;
}a[1001000];
void kls(int x,int fa){
	int tt=1e15+7,pp=0;
	for (int i=0;i<G1[x].size();i++){
		if (G2[x][i]<tt&&(!(vis[x]==true&&vis[pp]==true))) {
			tt=G2[x][i];
			pp=G1[x][i];
		}
	}
	if (vis[x]==true&&vis[pp]==true) return ;
	if (pp!=0){
		vis[x]=true;
		vis[pp]=true;
		ans+=tt;
		kls(pp,x);
	}
}
/*void dfs(int x){
	if (x==k){
		int tot=0;ans=0;
	for (int i=1;i<=k;i++){
		if (f[i]==1){
	        ans+=b[i][0];
	        
		}
	}
	  return ;		
	}
	x+=1;
	f[x]=1;
	dfs(x);
	f[x]=0;
	dfs(x);
}*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
//	cout<<n<<endl;
	for (i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		G1[a[i].u].push_back(a[i].v);
		G1[a[i].v].push_back(a[i].u);
		G2[a[i].u].push_back(a[i].w);
		G2[a[i].v].push_back(a[i].w);
	}
//	cout<<1<<endl;
	if (k==0){
		for (i=1;i<=n;i++)
		  vis[i]=false;
//	cout<<n<<endl;		  
		for (i=1;i<=n;i++){
			if (vis[i]==true) continue;
//				cout<<1<<endl;
	    	kls(i,-1);
//	    	cout<<1<<endl;
	}
//	for (i=1;i<=n;i++)
//	  if (vis[i]==true)  cout<<"1";
	printf("%lld\n",ans);
	return 0;
	}
	for (i=1;i<=k;i++){
		scanf("%lld",&b[i][0]);
		for (j=1;j<=n;j++)
		  scanf("%lld",&b[i][j]);
		for (j=1;j<=n;j++)
		  G1[n+i].push_back(j),G1[j].push_back(n+i),G2[n+i].push_back(b[i][j]),G2[j].push_back(b[i][j]);
	}
	for (i=1;i<=n+k;i++)
		  vis[i]=false;
		for (i=1;i<=n;i++){
			if (vis[i]) continue;
//			cout<<ans<<endl;
	    	kls(i,-1);
	}
	printf("%lld\n",ans);
}