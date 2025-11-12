#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+100,M=1e6+10;
long long n,m,k;long long ans=1e18;
long long a[15][N];long long c[15];
bool cmp(array<long long,3> a,array<long long,3> b){
	return a[2]<b[2];
} 

struct Edge{
	vector<long long> f;
	Edge (long long n):f(n+1){
		iota(f.begin(),f.end(),0);
	}
	long long find(long long x){
		if(x==f[x]) return x;
		return f[x]=find(f[x]);
	}
	bool mem(long long a,long long b){
		long long fa=find(a),fb=find(b);
		if(fa==fb) return false;
		f[fb]=fa;
	}
	bool check(long long a,long long b){
		long long fa=find(a),fb=find(b);
		if(fa==fb) return true;
		return false;
	}
};
long long u[M],v[M],w[M];
void work1(){
	for(int i=0;i<(1<<k);i++){
		long long num=0;
		vector<array<long long,3>> node;
		for(int d=1;d<=m;d++){
			node.push_back({u[d],v[d],w[d]});
			node.push_back({v[d],u[d],w[d]});
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				num+=c[j+1];
				for(int u=1;u<=n;u++){
					node.push_back({n+j+1,u,a[j+1][u]});
					node.push_back({u,n+j+1,a[j+1][u]});
				}
			}
		}
		sort(node.begin(),node.end(),cmp);
		Edge st(n+100);
		vector<long long> vis(n+1,0);long long res=0;
		for(int u=0;u<node.size();u++){
			if(st.check(node[u][0],node[u][1])==false){
				st.mem(node[u][0],node[u][1]);
				if(node[u][1]<=n){
					if(!vis[node[u][1]]){
						vis[node[u][1]]=1;
						res++;
					}
				}
				if(node[u][0]<=n){
					if(!vis[node[u][0]]){
						vis[node[u][0]]=1;
						res++;
					}
				}
				num+=node[u][2];
			}
			if(res==n) break;
		}
		ans=min(ans,num);
	}
	cout<<ans;
}
void work2(){
		long long num=0;
		vector<array<long long,3>> node;
		for(int d=1;d<=m;d++){
			node.push_back({u[d],v[d],w[d]});
			node.push_back({v[d],u[d],w[d]});
		}
		for(int j=0;j<k;j++){
				for(int u=1;u<=n;u++){
					node.push_back({n+1,u,a[j+1][u]});
					node.push_back({u,n+1,a[j+1][u]});
				}
		}
		sort(node.begin(),node.end(),cmp);
		Edge st(n+100);
		vector<long long> vis(n+1,0);long long res=0;
		for(int u=0;u<node.size();u++){
			if(st.check(node[u][0],node[u][1])==false){
				st.mem(node[u][0],node[u][1]);
				if(node[u][1]<=n){
					if(!vis[node[u][1]]){
						vis[node[u][1]]=1;
						res++;
					}
				}
				if(node[u][0]<=n){
					if(!vis[node[u][0]]){
						vis[node[u][0]]=1;
						res++;
					}
				}
				num+=node[u][2];
			}
			if(res==n) break;
		}
		ans=min(ans,num);
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];	
	}
	int flg=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flg=0;
		for(int j=1;j<=n;j++)	
			cin>>a[i][j];
	}
	if(flg==1) work2();
	else work1();
	return 0;
} 