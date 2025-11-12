#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll Mod=998244353;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
ll n,a[N],s[N],ans;
void dfs(int now,ll sum){
	for(int i=now+1;i<=n;i++){
		if(sum>a[i])ans=(ans+1)%Mod;
//		printf("%d,%d,%lld\n",now,i,sum+a[i]);
		dfs(i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		s[i]=s[i-1]+a[i];
//	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
//	for(int G=3;G<=n;G++){
//		
//	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dfs(j,a[i]+a[j]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

