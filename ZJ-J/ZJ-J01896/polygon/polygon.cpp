#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=998244353;
int n,a[5005],ans=0;
void dfs(int num,int wz,int maxx,int ssum,int sm){
	if(sm==num){
		if(maxx*2<ssum) ans++;
		return ;
	}
	for(int i=wz+1;i<=n;i++){
		dfs(num,i,max(maxx,a[i]),ssum+a[i],sm+1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,0);
	}
	cout<<ans;
	return 0;
}
