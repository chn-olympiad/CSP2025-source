#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n , a[5][N] , maxv ;
bool vis[N] ;

void dfs(int i , ll ans , int a1 , int a2 , int a3){
	if(a1>n/2 || a2>n/2 || a3>n/2)
		return;
	if(i>n){
		maxv=max(maxv,ans);
		return;
	}
	dfs(i+1,ans+a[1][i],a1+1,a2,a3);
	dfs(i+1,ans+a[2][i],a1,a2+1,a3);
	dfs(i+1,ans+a[3][i],a1,a2,a3+1);
}

void solve(){
	maxv=0;
	cin >> n ;
	for(int i=1;i<=n;i++)
		cin>> a[1][i] >> a[2][i] >> a[3][i] , vis[i]=0;
	dfs(1,0,0,0,0);
	cout << maxv << '\n'; 
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t ;
	while(t--)
		solve();
	return 0;
}
