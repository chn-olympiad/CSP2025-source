#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505],ans;
string s;
int v1[15],v2[15];
void panduan(){
	int he=0,tui=0;
	for(int i=1;i<=n;i++){
		if(tui>=c[v2[i]]){
			tui++;
			continue;
		}
		if(s[i-1]=='0'){
			tui++;
			continue;
		}
		he++;
	}
	if(he>=m)ans++;
}
void dfs(int x){
	if(x>n){
		panduan();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v1[i]){
			v1[i]=1;
			v2[x]=i;
			dfs(x+1);
			v1[i]=0;
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0')return false;
	}
	return true;
}
int num[505],ji[505];
int qm(int a,int b){
	int sum=1;
	while(b){
		if(b&1)sum=sum*a%mod;
		a=a*a%mod;b>>=1;
	}
	return sum;
}
int C(int x,int y){
	return ji[x]*qm(ji[y],mod-2)%mod*qm(ji[x-y],mod-2)%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	ji[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		num[c[i]]++;
		ji[i]=ji[i-1]*i%mod;
	}
	if(n<=10){
		dfs(1);
	}
	else if(m==n){
		if(check()&&!num[0])ans=ji[n];
	}
	cout<<ans%mod;
	return 0;
}
/*
17:25骗分来。
18:03牢完了，只有暴力分。
12pts。
*/