#include<bits/stdc++.h>
using namespace std;
const int N=555,mod=998244353;
int n,m,a[N],path[N],ans;
char s[N];
bool f[N];
void dfs(int cnt,int num){
	if(cnt>n){
		if(n-num>=m) ans++;
		if(ans>=mod) ans-=mod;
		return;
	}
	if(n-num<m) return;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		path[cnt]=a[i];
		f[i]=1;
		if(num>=a[i]||s[cnt]=='0'){
			dfs(cnt+1,num+1);
		}else{
			dfs(cnt+1,num);
		}
		f[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	printf("%d",ans%mod);
	return 0;
}
