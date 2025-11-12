#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n , a[N] , ans , maxn ;

void dfs(int x , int num , int maxv){
	if(x>n){
		if(num>2*maxv){
			ans++;
		}
		return;
	}
	dfs(x+1,num+a[x],max(maxv,a[x]));
	dfs(x+1,num,maxv);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
