//#include <bits/stdc++.h>
//using namespace std;
//
//namespace quick_io{
//	template<typename T>
//	void input(T &x){
//		x=0;
//		bool f=0;
//		char ch=' ';
//		while(ch<'0'||ch>'9'){
//			if(ch=='-') f=1;
//			ch=getchar();
//		}
//		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
//		if(f) x=-x;
//	}
//
//	template<typename T>
//	void print(T x){
//		if(x<0) putchar('-'),x=-x;
//		if(x>10) print(x/10);
//		putchar(x%10+'0');
//	}
//}
//using namespace quick_io;
//#define int long long
//const int N=1e4+10;
//const int M=1e6+10;
//const int K=10+2;
//
//int n,m,k;
//
//int l[M<<1],ne[M<<1],head[N],tail[N],e[M<<1],idx;
//void con(int u,int v,int val){
//	idx++;
//	l[idx]=v;
//	if(head[u]) ne[tail[u]]=idx;
//	else head[u]=idx;
//	tail[u]=idx;
//}
//
//struct Road{
//	int u,v;
//	int cost;
//};
//vector<Road> road;
//vector<Road> v1,v2;
//
//bool cmp(Road A,Road B){
//	return A.cost<B.cost;
//}
//
//int FA[N];
//int find(int x){
//	if(FA[x]==x) return x;
//	else return FA[x]=find(FA[x]);
//}
//
//int kruskral(){
//	int res=0;
//	for(int i=1;i<=n;i++) FA[i]=i;
//	sort(road.begin(),road.end(),cmp);
//	for(auto x:road){
//		int u=x.u;
//		int v=x.v;
//		if(find(u)==find(v)) continue;
//		v1.push_back(x);
//		FA[find(u)]=find(v);
//		con(u,v,x.cost);
//		con(v,u,x.cost);
//		res+=x.cost;
//	}
//	return res;
//}
//
//int f[K][N];
//
//int fa[N],dfn[N],sz[N],cnt;
//void dfs(int u){
//	cnt++;
//	dfn[u]=cnt;
//	sz[u]=1;
//	for(int i=head[u];i;i=ne[i]){
//		int v=l[i];
//		if(fa[u]==v) continue;
//		fa[v]=u;
//		dfs(v);
//		sz[u]+=sz[v];
//	}
//}
//
//int st[K][N][20],lg[N];
//void init(){
//	lg[1]=0;
//	for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
//	for(int t=0;t<k;t++){
//		for(int i=1;i<=n;i++) st[t][i][0]=f[t][dfn[i]];
//		for(int j=1;j<=18;j++)
//			for(int i=1;i+(1<<j)-1<=n;i++){
//				st[t][i][j]=min(st[t][i][j-1],st[t][i+(1<<j)-1][j-1]);
//			}
//	}
//}
//
//int query(int t,int l,int r){
//	int len=(r-l+1);
//	return min(st[t][l][lg[len]],st[t][r-lg[len]][lg[len]]);
//}
//
//int cost[1<<K];
//signed main(){
//	freopen("road1.in","r",stdin);
////	freopen("road.out","w",stdout);
//	input(n);
//	input(m);
//	input(k);
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		input(u);
//		input(v);
//		input(w);
//		road.push_back({u,v,w});
//	}
//	
//	int ans=kruskral();
//	
//	for(int i=0;i<k;i++)
//		for(int j=0;j<=n;j++)
//			input(f[i][j]);
//	dfs(1);
//	init();
////	for(int i=1;i<=n;i++) cout<<dfn[i]<<" ";
////	for(int i=0;i<=18;i++) cout<<st[0][dfn[4]][i]<<" ";
//	for(int i=0;i<(1<<k);i++)
//		for(int j=0;j<k;j++)
//			if(i&(1<<j))
//				cost[i]+=f[j][0];
//	for(int i=0;i<(1<<k);i++){
//		int sum=cost[i];
//		v2=v1;
//		for(int j=0;j<k;j++){
//			if(!(i&(1<<j))) continue;
//			for(auto &x:v2){
//				if(fa[x.u]==x.v) swap(x.u,x.v);
//				int c1,c2;
//				c1=query(j,dfn[x.v],dfn[x.v]+sz[x.v]-1);
//				c2=query(j,1,dfn[x.v]-1);
//				if(dfn[x.v]+sz[x.v]-1<n) c2=min(c2,query(j,dfn[x.v]+sz[x.v]-1,n));
////				if(i==1) cout<<x.u<<" "<<x.v<<" "<<c1+c2<<endl;
//				x.cost=min(x.cost,c1+c2);
//			}
//		}
////		cout<<endl;
//		for(auto x:v2) sum+=x.cost;
//		ans=min(ans,sum);
//		if(i!=1) continue;
//		for(auto x:v2) cout<<x.u<<" "<<x.v<<" "<<x.cost<<endl;
//		cout<<endl;
//	}
//	print(ans);
//}

#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}

	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>10) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;
#define int long long
const int N=1e4+10;
const int M=1e6+10;
const int K=10+2;

int n,m,k;

struct Road{
	int u,v;
	int cost;
};
vector<Road> road;

bool cmp(Road A,Road B){
	return A.cost<B.cost;
}

int FA[N];
int find(int x){
	if(FA[x]==x) return x;
	else return FA[x]=find(FA[x]);
}

int kruskral(int n){
	int res=0;
	for(int i=1;i<=n;i++) FA[i]=i;
	sort(road.begin(),road.end(),cmp);
	for(auto x:road){
		int u=x.u;
		int v=x.v;
		if(find(u)==find(v)) continue;
		FA[find(u)]=find(v);
		res+=x.cost;
	}
	return res;
}
int f[K][N];

int cost[1<<K],cnt[1<<K];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input(n);
	input(m);
	input(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		input(u);
		input(v);
		input(w);
		road.push_back({u,v,w});
	}
	
	int ans=kruskral(n);
	
	//Test 1
	if(k==0){
		print(ans);
		return 0;
	}
	
	for(int i=0;i<k;i++)
		for(int j=0;j<=n;j++)
			input(f[i][j]);
	
	for(int i=0;i<(1<<k);i++)
		for(int j=0;j<k;j++)
			if(i&(1<<j))
				cost[i]+=f[j][0],cnt[i]++;
	for(int i=0;i<(1<<k);i++){
		int sum=cost[i];
		for(int j=0;j<k;j++){
			if(!(i&(1<<j))) continue;
			for(int u=1;u<=n;u++)
				road.push_back({j,u,f[j][u]});
		}
		ans=min(ans,sum+kruskral(n+cnt[i]));
		for(int j=1;j<=cnt[i];j++){
			for(int u=1;u<=n;u++)
				road.pop_back();
		}
	}
	print(ans);
}
