#include<bits/stdc++.h>
using namespace std;
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
#define endl '\n'

// 1823 sample1 Ô¤¹À 0 ~ 4 ·Ö 
constexpr int N = 550;
constexpr int mod = 998244353;
int c[N];
int ans = 0;
int n,m;
string s;
bool visit[N];
void dfs(int x,int refuse){
	if(refuse > n - m)return ;
	if(x == n && n - refuse == m)ans ++;
	for(int i = 1;i <= n;i ++){
		if(!visit[i]){
			visit[i] = true;
			dfs(x + 1,refuse + (s[i] - '0' == 0 || refuse >= c[i]));
			visit[i] = false;
		}
	}
}
signed main(){
	fileIO("employ"); 
	cin.tie(0);cout.tie(0);

	cin >> n >> m >> s;
	for(int i = 1;i <= n;i ++){
		cin >> c[i];
	} 
	if(n <= 10){
		for(int i = 1;i <= n;i ++){
			visit[i] = true;
			dfs(1,(s[i] - '0' == 0 || c[i] == 0 ? 1 : 0));
			visit[i] = false;
		}
		cout << ans << endl;
	} 
	return 0;
}

