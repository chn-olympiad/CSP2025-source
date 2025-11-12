#include<bits/stdc++.h>
using namespace std;
const int N=10010;
const int M=1000010;
const int inf=0x7fffffff;
int n,m,k,cnt,num;
int head[N*2];
bool vis[N]; 
long long dis[N*2];
long long c[N*2];//Improving cost
long long ans;
long long a[20][N];
long long mp[1010][1010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		dis[i]=inf;
		for(int j=1;j<=n;j++)
			mp[i][j]=inf;
		mp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		mp[x][y]=z;
		mp[y][x]=z;
	}		
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(flag==0&&n<=1000){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					mp[z][j]=min(mp[z][j],a[i][j]+a[i][z]);
					mp[j][z]=mp[z][j];
				}
			}
		}
//		for(int i=1;i<=k;i++)
//			for(int j=1;j<=n;j++)
//				cout<<a[i][j]<<' ';
//			cout<<endl;
//		}
		int u=1;
		dis[1]=0;
		vis[1]=1; //Connected cities
		num=1;  //Connected cities number
		while(num<n){
//			cout<<"&&&"<<u<<' '<<ans<<"---\n";
			for(int i=1;i<=n;i++){
				long long v=i,w=mp[u][i];
				if(!vis[v]){
					dis[v]=min(dis[v],w);
				} 
			}
			long long minn=inf;
			int min_pos;
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(dis[i]<minn){
					minn=dis[i];
					min_pos=i;
				}
			}
			num++;
			vis[min_pos]=1;
			ans+=minn;
			u=min_pos;
		}
		cout<<ans<<'\n';
		return 0;
	}
//	for(int e=0;e<=((1<<k)-1);e++){
//		for(int j=1;j<=k;j++){
//			if((e-(int)pow(2,j-1))%2==1){
//				
//			}
//		}
//		
//	}
	/*int u=1;
	vis[1]=1; //Connected cities
	num=1;  //Connected cities number
	while(num<n){
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].t,w=edge[i].val;
			if(!vis[v]){
				dis[v]=min(dis[v],(long long)w);
			} 
		}
		for(int i=head[u+n];i;i=edge[i].next){
			int v=edge[i].t,w=edge[i].val;
			if(!vis[v]){
				dis[v]=min(dis[v],c[u+n]+w);
			}
		}
		long long minn=inf;
		int min_pos;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(dis[i]<minn){
				minn=dis[i];
				min_pos=i;
			}
		}
		num++;
		vis[min_pos]=1;
		ans+=minn;
		u=min_pos;
	}
	cout<<ans<<'\n';*/
	return 0;
}
//chzx_lfw AK IOI!!!!! 
//
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13

*/
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 2 2 3 5
0 2 2 3 3
*/
