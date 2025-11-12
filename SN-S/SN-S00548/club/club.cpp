#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c;
}u[100000];
int dp[1000][1000];
int cmp(st x,st y){
	return x.a > y.a;
}
void solve(){
	int b;
	cin >> b;
	int ans = 0;
	for(int i = 1;i <= b;i ++){
		cin >> u[i].a >> u[i].b >> u[i].c;
	}
	sort(u+1,u+b+1,cmp);
	for(int i = 1;i <= b/2;i ++){
		ans += u[i].a;
	}
	cout << ans << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
