#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int z,it,dir;
	bool operator <(const node B)const {
		return B.z>z;
	}
};
priority_queue<node>mp;
int cnt,tot;
int a[100010][4];
bool isbal[4];
int vis[100010];
struct man{
	int z,it,dir;
	bool operator <(const man B)const {
		return dir<B.dir;
	}
};
priority_queue<man>lis[4];

int gtz(int ptr,int dir){
	if(dir==1)return max(a[ptr][2],a[ptr][3]);
	if(dir==2)return max(a[ptr][1],a[ptr][3]);
	return max(a[ptr][2],a[ptr][1]);
}
void gt(){
	while(!mp.empty()){
		int u=mp.top().it,g=mp.top().z,pz=mp.top().dir;
//		cout<<u<<" "<<g<<" "<<endl;
		mp.pop();
		if(vis[u]||(!isbal[pz]))continue;
		cnt++;tot+=g;vis[u]=1;
		lis[pz].push({-g,u,gtz(u,pz)-g});
	}
}
void bal(int part){
	isbal[part]=0;
//	cout<<part<<endl;
	while(lis[part].size()>(n>>1)){
		int u=lis[part].top().it,g=lis[part].top().z;
		lis[part].pop();
		vis[u]=0;
		cnt--;tot+=g;
		for(int i=1;i<=3;i++){
			if(isbal[i]){
				mp.push({a[u][i],u,i});
			}
		}
	}
}
void init(){
	isbal[1]=isbal[2]=isbal[3]=1;tot=0;
	while(!mp.empty())mp.pop();
	while(!lis[1].empty())lis[1].pop();
	while(!lis[2].empty())lis[2].pop();
	while(!lis[3].empty())lis[3].pop();
	cnt=0;
}
void solve(){
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			mp.push({a[i][j],i,j});
		}
	}
	gt();
//	cout<<lis[1].top().dir<<endl;
	for(int i=1;i<=3;i++){
		if(lis[i].size()>(n>>1)){
			bal(i);	
			gt();
		}
	}
	cout<<tot<<"\n";
}
int T;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/