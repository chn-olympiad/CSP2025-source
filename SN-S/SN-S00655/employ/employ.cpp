#include<bits/stdc++.h>
#define lint long long
using namespace std;
int n,m,ans,a[5005],c[5005];
char s[5005];
bool v[5005];
void dfs(int p){
	if(p > n){
		int nb = 0,tt = 0;
		for(int i = 1;i <= n;i++){
			if(tt >= c[a[i]] || !s[a[i]]){
				tt++;
			}
			else nb++;
		}
		if(nb >= m) ans++;
	}
	for(int i = 1;i <= n;i++){
		if(v[i]) continue;
		a[p] = i;
		v[i] = true;
		dfs(p + 1);
		v[i] = false;
		a[p] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= n;i++) cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}
