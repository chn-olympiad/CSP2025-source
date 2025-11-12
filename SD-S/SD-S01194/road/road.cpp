#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
vector<pair<int,int> > mp[N];
int c[N];
int costs[15][N];
int ans=0x3f3f3f3f;
void dfs1(){
}
void dfs2(){
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans_t=0;
	for(int i=1;i<=m;i++){
		int st,to,cst;
		cin>>st>>to>>cst;
		ans_t=ans_t+cst;
		mp[st].push_back({to,cst});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>costs[i][j];
		}
	}
	cout<<ast_t;
	if(k==0){
		
	}else{
		
	}
	return 0;
}
