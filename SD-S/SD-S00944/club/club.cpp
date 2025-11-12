#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long 
using namespace std;

const int N=1e5+10;
struct Node1{
	int w,id;
	int operator<(Node1 y)const{return w>y.w;}
};
struct Node2{
	int w,id1,id2;
	int operator<(Node2 y)const{return w>y.w;}
};
vector<Node1> c[N];
priority_queue<Node2> q[4];
int a[N][4], cnt[4], b[N];
int n, m, ans;

inline void Init(){
	for(int i=0; i<=n; i++){
		a[i][1]=cnt[1]=a[i][2]=cnt[2]=a[i][3]=cnt[3]=b[i]=0;
		
	}
	for(int i=0; i<=n; i++) c[i].clear();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	while(!q[3].empty()) q[3].pop();
	ans=0;
}
void FAST(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void Dfs(int x){
	if(x>n){
		int ANS=0;
		for(int i=1; i<=n; i++) ANS+=a[i][b[i]];
		ans=max(ans,ANS); return;
	}
	for(int i=1; i<=3; i++){
		if(cnt[i]==(n>>1))continue;
		b[x]=i; cnt[i]++;
		Dfs(x+1);
		b[x]=0; cnt[i]--;
	}
}


void solve(){
	cin>>n;
	Init();
	for(int i=1; i<=n; i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		c[i].emplace_back(Node1{a[i][1],1});// 0_base 
		c[i].emplace_back(Node1{a[i][2],2});
		c[i].emplace_back(Node1{a[i][3],3});
	}
	if(n<=10){
		Dfs(1); cout<<ans<<"\n"; return; 
	} 
	//cnt: 1base 
	for(int i=1; i<=n; i++)
		stable_sort(c[i].begin(), c[i].end());
	q[c[1][0].id].push(Node2{c[1][0].w, 1,0}); cnt[c[1][0].id]++;
	int ID1, ID2, W; Node1 nxt;
	for(int i=2; i<=n; i++){
		for(int j=0; j<3; j++){
			if(cnt[c[i][j].id]<(n>>1)){
				q[c[i][j].id].push(Node2{c[i][j].w, i,j});
				cnt[c[i][j].id]++; break;
			}
			ID1=q[c[i][j].id].top().id1;
			ID2=q[c[i][j].id].top().id2;
			W=q[c[i][j].id].top().w;
			if(ID2==2)continue;
			ID2++;
			while(ID2<2 && cnt[c[ID1][ID2].id]>=(n>>1))
				ID2++;
			nxt=c[ID1][ID2];
			if(cnt[nxt.id]>=(n>>1))continue;
			if(-W+nxt.w+c[i][j].w > 0){
				q[c[i][j].id].pop();// cnt-- 
				q[c[i][j].id].push(Node2{c[i][j].w, i,j});// cnt++
				
				q[nxt.id].push(Node2{nxt.w, ID1,ID2});
				cnt[nxt.id]++;
				break;
			}
		}
	}
	for(int i=1; i<=3; i++){
		while(!q[i].empty()){
			ans+=q[i].top().w; q[i].pop();
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	FAST();
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
} 
