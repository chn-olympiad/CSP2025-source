#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005],n,front[5005],ans;
bool flag = true;
void dfs(int r,int maxa,int gotlen,int gotnum){
	if(gotnum >= 3 && gotlen > maxa){
		ans = (ans+1)%mod;
	}
	for(int i = r-1;i >= 1;i--){
		if(front[r-1]+gotlen <= maxa) break;
		dfs(i,maxa,gotlen+a[i],gotnum+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	front[0] = 0; 
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i] != 1) flag = false;
	}
	if(flag){
		ans = 1;
		for(int i = 1;i <= n;i++) ans = (ans*2)%mod;
		ans = (ans-(n*(n-1))/2-n-1)%mod;
		printf("%d",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) front[i] = front[i-1]+a[i];
	for(int i = n;i >= 3;i--){
		dfs(i,a[i],0,1);
	}
	printf("%d",ans);
	return 0;
}
