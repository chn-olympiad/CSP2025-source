#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],cnt = 0,bro;
bool check(){
	long long s = 0,m = 0,p = 0;
	for(int i = 1;i <= n;i++){
		if(vis[i] == 1){
			s += a[i];
			m = max(m,a[i]);
			p++;
		}
	}
	if(p >= 3 && s > m*2){
		return true;
	}else{
		return false;
	}
}
void dfs(long long x){
	if(x == n+1){
		if(check()){
			cnt = (cnt+1)%998244353;
		}
		return;
	}
	vis[x] = 1;
	dfs(x+1);
	vis[x] = 0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
