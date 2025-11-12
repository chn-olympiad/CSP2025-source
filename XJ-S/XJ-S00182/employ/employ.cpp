#include <bits/stdc++.h>
using namespace std;
bool vis[5001];
int n,m;
int ans = 0;
void dfs(int x){
	if(x == m + 1){
		ans++;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	//ÌØÊâÐÔÖÊA 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	char a[1001];
	cin >> a;
	int p[1001];
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	dfs(m);
	cout << ans;
	return 0;
}
