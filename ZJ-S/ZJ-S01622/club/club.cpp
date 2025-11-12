#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],vis[100005],k,ans;
long long check(){
	long long sum = 0;
	for(int i = 1;i <= n;i++){
		sum += a[i][vis[i]];
	}
	return sum;
}
void dfs(long long r,long long x,long long y,long long z){
	if(r == n+1){
		ans = max(ans,check());
		return;
	}
	if(x < k){
		vis[r] = 1;
		dfs(r+1,x+1,y,z);
	}if(y < k){
		vis[r] = 2;
		dfs(r+1,x,y+1,z);
	}if(z < k){
		vis[r] = 3;
		dfs(r+1,x,y,z+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		k = n/2;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
