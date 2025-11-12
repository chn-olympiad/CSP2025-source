#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int s[5005];
int r;
long long cnt;
void dfs(int x,int mx){
	if(x>n){
		if(r>2*a[mx]){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	r+=a[x];
	dfs(x+1,x);
	r-=a[x];
	dfs(x+1,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<cnt;
	return 0;
}
