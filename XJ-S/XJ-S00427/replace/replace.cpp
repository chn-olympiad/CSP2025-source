#include<bits/stdc++.h>
using namespace std;
int t,n,x[101],y[101],z[101],ans;
void dfs(int i,int a,int b,int c,int l1,int l2,int l3){
	if(l1 > n/2)return;
	if(l2 > n/2)return;
	if(l3 > n/2)return;
	if(i == n+1){
		ans = max(ans,a+b+c);
		return;
	}
	dfs(i+1,a+x[i],b,c,l1+1,l2,l3);
	dfs(i+1,a,b+y[i],c,l1,l2+1,l3);
	dfs(i+1,a,b,c+z[i],l1,l2,l3+1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> x[i] >> y[i] >> z[i];
		}
		dfs(1,0,0,0,0,0,0);
		cout << ans << '\n';
	}
}
