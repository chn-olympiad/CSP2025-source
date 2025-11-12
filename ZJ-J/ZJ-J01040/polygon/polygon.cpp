#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int MAXN=5050;
int n;
int a[MAXN];
bool vis[MAXN];
int ans;
void dfs(int w,int e,int j,int sm,int mx){
	if(w==e){
		if(sm>2*mx)
			ans++;
		ans%=mod;
		return;
	}
	for(int i=j+1;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(w,e+1,i,sm+a[i],max(mx,a[i]));
		vis[i]=0;
	}
	return;
}
void solve(){
	if(n<3)
		return;
	if(n==3){
		if(a[1]+a[2]>a[3])
			ans++;
		return;
	}
	if(n==4){
		if(a[1]+a[2]>a[3])
			ans++;
		if(a[1]+a[3]>a[4])
			ans++;
		if(a[3]+a[2]>a[4])
			ans++;
		if(a[1]+a[2]>a[4])
			ans++;
		if(a[1]+a[2]+a[3]>a[4])
			ans++;
		return;
	}
	if(n>=5){
		for(int i=3;i<=n;i++){
			dfs(i,0,0,0,0);
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	solve();
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}