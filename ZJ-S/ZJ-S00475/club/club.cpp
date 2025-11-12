/*
this fvv, whose luogu uid is 869164, cannot solve T1
fc c
ukcf
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;

int n;
int a[N][5];
int dp[N][4];

map<int, map<int, map<int, int>>> mp;

namespace subtask1{
	int ans = 0;
	void dfs(int l, int x, int y, int z, int st){
		if(x > n/2 || y > n/2 || z > n/2)return ;
		if(l == n+1)return ans = max(ans, st), void();
		
//		if(x+1 <= n/2)if(st+a[l][1] > mp[x+1][y][z])dfs(l+1, x+1, y, z, st+a[l][1]), mp[x+1][y][z] = st+a[l][1];
//		if(y+1 <= n/2)if(st+a[l][2] > mp[x][y+1][z])dfs(l+1, x, y+1, z, st+a[l][2]), mp[x][y+1][z] = st+a[l][2];
//		if(z+1 <= n/2)if(st+a[l][3] > mp[x][y][z+1])dfs(l+1, x, y, z+1, st+a[l][3]), mp[x][y][z+1] = st+a[l][3];
		
		if(x+1 <= n/2)dfs(l+1, x+1, y, z, st+a[l][1]);
		if(y+1 <= n/2)dfs(l+1, x, y+1, z, st+a[l][2]);
		if(z+1 <= n/2)dfs(l+1, x, y, z+1, st+a[l][3]);
	}
	
	signed main(){
		mp.clear();
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout<<ans<<endl;
	}
}

namespace subtask2{
	struct node{
		int l, x, y, z, s;
		bool operator < (const node& oth) const{
			return s > oth.s;
		}
	};
	
	signed main(){
		priority_queue<node> q;
		q.push({1, 0, 0, 0, 0});
		
		int ans = 0;
		while(!q.empty()){
			node now = q.top();q.pop();
			ans = max(ans, now.s);
			if(now.x+1 <= n/2)q.push({now.l+1, now.x+1, now.y, now.z, now.s+a[now.l][1]});
			if(now.y+1 <= n/2)q.push({now.l+1, now.x, now.y+1, now.z, now.s+a[now.l][2]});
			if(now.z+1 <= n/2)q.push({now.l+1, now.x, now.y, now.z+1, now.s+a[now.l][3]});
		}
		cout<<ans<<endl;
	}
}

signed main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);Äã±»Æ­ÁË 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;cin>>t;
	while(t--){
		memset(dp, 0, sizeof dp);
		cin>>n;
		for(int i = 1; i <= n; i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= 3; j++){
//				for(int k = 1; k <= 3; k++){
//					dp[i][j] = max(dp[i][j], dp[i-1][k]+a[i][j]);
//				}
//			}
//		}

//		cout<<max(dp[n][1], max(dp[n][2], dp[n][3]))<<" ";
		subtask1 :: main();//, subtask2 :: main();
//		if(n <= 10)subtask1 :: main();
//		else subtask2 :: main();
	}
	
	return 0;
}

/*
guys im gonna be afo
so just lemme be one of the oier listed in the 'misunderstanding behaviors show'
*/
