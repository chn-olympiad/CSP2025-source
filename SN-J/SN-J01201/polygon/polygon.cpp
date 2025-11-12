#include<bits/stdc++.h> 
using namespace std;
int noleg,animalpre[5005],vis[5005],ans;
const int mod = 998244353;
void dfs(int step){
	if(step > noleg){
		int maxn = 0,sum = 0;
		for(int i = 1;i <= noleg;i++){
			if(vis[i] == 1){
				sum += animalpre[i];
				maxn = max(maxn,animalpre[i]);
			}
		}
		if(sum > (2*maxn)) ans++;
		return;
	}
	for(int i = 0;i <= noleg;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(step+1);
			vis[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> noleg;
	for(int i = 1;i <= noleg;i++) cin >> animalpre[i];
	dfs(1);
	cout << ans/80%mod;
	return 0;
}
