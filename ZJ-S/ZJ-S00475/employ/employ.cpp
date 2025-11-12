/*
�ҵ�������¼ȡ�˲���ȥ¼�� 
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e2+5;
const int mod = 998244353;

int n, m, mx = 0;
string s;
int a[N];
map<int, int> mp;
int pw[N];

namespace subtask1{
	int vis[N];
	
	int ans = 0;
	
	void dfs(int t, int f, int g, int l){
//		cout<<t<<" "<<f<<" "<<g<<" "<<l<<endl;
//		if(g+(n-t+1) < m)return ;
		if(n-f < m)return ;
		if(g >= m)return ans = (ans + pw[n-t+1]) % mod, void();
		
		for(int i = 1; i <= n; i++){
			if(f >= a[i])continue;
			if(vis[i])continue;
			if(s[t-1] == '1')vis[i] = 1, dfs(t+1, f, g+1, i), vis[i] = 0;
			else vis[i] = 1, dfs(t+1, f+1, g, i), vis[i] = 0;
		}
	}
	
	int main(){
		
		memset(vis, 0, sizeof vis);
		dfs(1, 0, 0, 0);
		cout<<ans;
	}
}


int main(){
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);�㱻ƭ�� 
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	pw[0] = 1;for(int i = 1; i <= n; i++)pw[i] = (pw[i-1] * i) % mod;
	for(int i = 1; i <= n; i++)cin>>a[i], mx = max(mx, a[i]), mp[a[i]]++;
	sort(a+1, a+n+1);
	subtask1 :: main();
}
/*
¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼¼
����uid869164 
*/ 
