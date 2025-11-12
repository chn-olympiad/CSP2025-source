#include<bits/stdc++.h>
using namespace std;

int n,k,a[10001],cnt = 0;

void dfs(int x,int w){
	if(w > n || w < 1){
		return;
	}
	if(x == k){
		cnt ++;
		dfs(a[w + 1],w + 1);
	}
	dfs(x ^ a[w + 1] , w + 1);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	dfs(a[1],1);
	cout << cnt;
	return 0; 
}
