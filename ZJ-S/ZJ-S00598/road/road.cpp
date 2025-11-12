#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define int long long
#define N 10005
#define MAX 1145141919810
#define endl "\n"
#define TXYAKIOI 91
#define mod 78
using namespace std;
int n,m,k,ans=MAX;
struct node{
	int to,val;
};
struct mn{
	int id,money,hav;
};
int u[N],v[N],w[N];
int a[15][N];
int wei[N];
bool flag[N];
inline void check(){
	int total=0;
	vector<node>Q[N];
	memset(Q,0,sizeof(Q));
	rep(i,1,m){
		Q[u[i]].push_back({v[i],w[i]});
		Q[v[i]].push_back({u[i],w[i]});
	}
	rep(i,1,k)
		if(flag[i]){
			total+=wei[i];
			rep(j,1,n)
				if(i!=j){
					int mt;
					if(Q[i][j].val!=0)mt=min(a[i][j],Q[i][j].val);
					else mt=a[i][j];
					Q[i].push_back({j,mt});
					Q[j].push_back({i,mt});	
				}
		}	
	queue<mn>s;
	s.push({1,0,0});
	while(!s.empty()){
		mn tmp=s.front();
		s.pop();
		int ID=tmp.id,ss=tmp.money,cc=tmp.hav;
		if(cc==n){ans=min(ans,total+ss);continue;}
		for(auto i:Q[ID])s.push({i.to,ss+i.val,cc+1});
	}
}
inline void dfs(int i){
	if(i>k){
		check();
		return;
	}
	flag[i]=true;
	dfs(i+1);
	flag[i]=false;
	dfs(i+1);
}
inline void Enchanted(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(flag,false,sizeof(flag));
	cin>>n>>m>>k;
	rep(i,1,m)cin>>u[i]>>v[i]>>w[i];
	rep(i,1,k){
		cin>>wei[i];
		rep(j,1,n)cin>>a[i][j];
	}
	dfs(1);
	cout<<ans;
}
signed main(){Enchanted();return 0;}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
/*

4 6 0
1 4 4
1 2 8
1 3 2
2 4 5
3 4 4 
2 3 7
*/
