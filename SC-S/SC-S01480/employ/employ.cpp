#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long n,m,ans=1;
string a;
long long atr[510],dp[510][510],c[510],num[510];
void solve1(){
	if(atr[n-1]==0){
		for(int i=1;i<=n;i++) ans=ans*i%p;
	}else ans=0;
}
void solve2(){
	for(int i=1;i<=n;i++) ans=ans*i%p;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>a;
	for(int i=0;i<n;i++){
		int x=a[i]-'0';
		if(x==0) atr[i]=atr[i-1]+1;
		else atr[i]=atr[i-1];
		printf("%lld ",atr[i]);
	}printf("\n");
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(n==m) solve1();
	else if(atr[n-1]==0) solve2();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
