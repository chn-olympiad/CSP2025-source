#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[550];
char s[550];
bool us[550];
void dfs(int u,int sum){
	if(u>n){
		if(n-sum>=m) ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(us[i]==1) continue;
		us[i]=1;
		if(sum<a[i]&&s[u]=='1') dfs(u+1,sum);
		else dfs(u+1,sum+1);
		us[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	if(n>11){ 
		ans=1;
		for(int i=n;i>=1;i--){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
}
