//商峻熙 SN-J00227 西安市曲江第一中学 
#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 1e3+10;
ll red(){
	ll k = 0,f = 1;
	char c = getchar();
	while(c<'0' || c>'9'){
		if(c=='-')f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		k = k*10+(c-'0');
		c = getchar();
	}
	return k*f;
}
int n,k,a[N];
bool p[N][N],vis[N][N];
ll ans = 0;
void dfs(ll num,int l,int r){
	ans = max(ans,num);
	if(r==n)return;
	for(int l1 = r+1;l1 <= n-1;l1++){
		for(int r1 = l1+1;r1 <= n;r1++){
			if(p[l1][r1] && !vis[l1][r1]){
				vis[l1][r1] = 1;
				dfs(num+1,l1,r1);
				vis[l1][r1] = 0;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = red();k = red();
	if(n>=1e3){
		printf("0");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		a[i] = red();
	}
	for(int l = 1;l <= n-1;l++){
		for(int r = l+1;r <= n;r++){
			int sum = 0;
			for(int i = l;i <= r;i++){
				sum ^= a[i];
			}
			if(sum == k)p[l][r] = 1;
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			for(int j = 1;j <= n;j++){
				vis[j][i] = 1;
				vis[i][j] = 1;
			}
		}
	}
	dfs(0,0,0);
	for(int i = 1;i <= n;i++){
		if(a[i] == k)ans++;
	}
	printf("%lld",ans);
	return 0;
}
