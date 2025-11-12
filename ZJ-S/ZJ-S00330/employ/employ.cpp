#include<bits/stdc++.h>
using namespace std;
int n,m,p,c[505],q[505],v[505],bg;
char a[505];
long long ans;
void dfs(int x){
	if(x==n){
		bg=0;
		for(int i=1;i<=n;i++){
			if(bg>=c[q[i]]){
				bg++;
				continue;
			}
			if(a[i-1]=='0'){
				bg++;
			}
		}
		if(n-bg>=m){
			ans++;
			ans%=998244353;
			return;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==1) continue;
		q[x+1]=i;
		v[i]=1;
		dfs(x+1);
		v[i]=0;
	}return;
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&a);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='1') p++;
	}
	if(p==n){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%998244353;
		printf("%lld",ans);
		return 0;
	}
	else if(n<=10){
		dfs(0);
		printf("%lld",ans);
	}
	else{
		sort(c+1,c+n+1);
		int sq=0;
		ans=1;
		for(int i=1;i<=n;i++){
			if(c[i]==c[i-1]||i==1) sq++;
			else{
				ans=ans*sq%998244353;
				sq=1;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
