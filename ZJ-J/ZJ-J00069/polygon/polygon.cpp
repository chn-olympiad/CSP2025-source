#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010],m,sum1,b[5010];
void dfs(int dep,int sum,int ma){
	if(dep==m+1){
		if(sum>ma*2){
			sum1++;
			sum1%=998244353;
		}
		return;
	}
	dfs(dep+1,sum,ma);
	dfs(dep+1,sum+a[dep],a[dep]);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	dfs(1,0,0);
	cout<<sum1;
}
