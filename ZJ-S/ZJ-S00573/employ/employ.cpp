#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=520;
int n,m,dp[N][N],c[N];
char s[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1,cmp);
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') {flag=0;break;}
	}
	if(flag){
		long long res=1;
		for(int i=2;i<=n;i++){
			res=(res*(1LL*i))%mod;
		}cout<<res;
		return 0;
	}
	return 0;
}
