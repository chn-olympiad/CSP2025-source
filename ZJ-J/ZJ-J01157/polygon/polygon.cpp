#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010;
int n,a[N],maxn;
ll ans,mul[N];
void slv1(){
	mul[0]=1;
	for(int i=1;i<=n;i++){
		mul[i]=mul[i-1]*i;
	}
	for(int i=3;i<n;i++){
		ans+=mul[n]/mul[n-i]/mul[i];
	}
	ans++;
}
void dfs(int x,int maxx,int sum){
	if(x>n){
		if(sum>maxx*2){
			ans++;
		}
		return;
	}
	dfs(x+1,max(maxx,a[x]),sum+a[x]);
	dfs(x+1,maxx,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		slv1();
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
