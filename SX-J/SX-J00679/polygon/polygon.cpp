#include <bits/stdc++.h>
using namespace std;
int const N = 5005;
int a[5005],index[5005];
int idx[5005];
int n;
int ret = 0;
void dfs(int nx, int now){
	if(now > nx) {
		int sum = 0;
		for(int i = 1; i <= nx; i++){
			sum+=index[i];
		}
		sort(index+1,index+nx+1);
		if(sum>index[nx]*2) ret++;
		return;
	}
	
	for(int i = now ; i <= n; i++){
		if(idx[i]==0){
			index[now]=i;
			idx[i]=1;
			dfs(nx,now+1);
			idx[i]=0;
		}
	}
	return;
}

int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	cin >> n;
	for(int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 3; i <= n; i++){
		dfs(i,1);
	}
	dfs(n-1,1);
	cout << ret;
	return 0;
}
