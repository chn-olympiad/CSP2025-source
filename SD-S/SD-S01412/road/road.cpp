#include<bits/stdc++.h>
#define int long long
#define g() getchar()
#define m(a,b) make_pair(a,b)
using namespace std;
const int N=1e6+10;
int n,m,K;
struct node{
	int u,v,w;
}a[N];
int e[N];
int g[20][N];
bool cmp1(node a,node b){
	return a.w<=b.w;
}
bool cmp(int i,int j){
	return i<=j;
}
map<pair<int,int> ,int> mp;
int c[N];
int vis[N];
int tot=0,num=0;
signed main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		mp[m(a[i].u,a[i].v)]=a[i].w;
	}
	for(int i=1;i<=K;i++){
		cin>>e[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	if(K==0){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<n;i++){
			num+=a[i].w;
		}
		cout<<num<<endl;
		return 0;
    }
    else {	
    	for(int j=1;j<=n;j++){
    		for(int k=j+1;k<=n;k++){
    			for(int i=1;i<=K;i++){
    				if(vis[i]==0)
					mp[m(j,k)]=min(mp[m(j,k)],g[i][j]+g[i][k]+e[i]),vis[i]=1;
					else
					mp[m(j,k)]=min(mp[m(j,k)],g[i][j]+g[i][k]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			c[++tot]=mp[m(u,v)];
		}
		sort(c+1,c+1+tot,cmp);
		for(int i=1;i<n;i++){
			num+=c[i];
		}
		cout<<num<<endl;
	}
	return 0;
}
