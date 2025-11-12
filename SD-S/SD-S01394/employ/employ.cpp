#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char s[502];
int c[502];
bool vis[502];
int a[502];
int ans=0;
int fac(int n){
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=(long long)ans*i%mod;
	return ans;
}
int check(){
	int cnt=0,ref=0;
	for(int i=1;i<=n;i++){
		if(s[i]-'0'==0){ref++;continue;}
		if(ref<c[a[i]])cnt++;
		else ref++;
	}
	return cnt;
}
void dfs(int k){
	if(k>n){
		int l=check();
		if(l>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
		a[k]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
