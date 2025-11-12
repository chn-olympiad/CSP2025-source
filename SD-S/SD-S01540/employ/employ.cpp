#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;

const int N = 22;
const int Mod = 998244353;

int a[505];
int c[505];
int n,m;
string s;
int vis[505];
int ans;
void dfs(int ii){
	if(ii==n+1){
		int num = 0;
		For(i, 1, n){
			if(s[i-1]=='0'){
				num ++;
			}else if(c[a[i]]<=num)num++;
		}
		if(n-num>=m){
			ans++;
		}
		return;
	}
	for(a[ii]=1;a[ii]<=n;a[ii]++){
		if(vis[a[ii]])continue;
		vis[a[ii]] = 1;
		dfs(ii+1);
		vis[a[ii]] = 0;
	} 
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	For(i, 1, n){
		cin >> c[i];
	}
	if(n>20){
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2

*/
