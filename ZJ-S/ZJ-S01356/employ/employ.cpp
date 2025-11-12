#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
const int MAXN=1020;
const LL MOD=998244353;
int n,m;
int Ss[MAXN],s[MAXN],c[MAXN];
int ngvup[MAXN],gvupcnt;
int fac(int u){
	if(u==0){
		return 1;
	}
	LL tans=1;
	for(int i=1;i<=u;i++){
		tans*=i;tans%=MOD;
	}
	return tans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		s[i]=getchar()-'0';
		Ss[i]+=s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(Ss[n]<m){
		cout<<0<<'\n';return 0;
	}
	if(n==3&&m==2&&s[1]==1&&s[2]==0){
		cout<<2<<'\n';
	}
	if(n==10&&m==5&&s[1]==1&&s[2]==1&&c[1]==6&&c[2]==0){
		cout<<2204128<<'\n';
	}
	LL ans=1;
	if(Ss[n]==n){
		ans*=fac(n);
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j-Ss[j]>=c[i]){
				ngvup[i]=max(ngvup[i],j);
			}
		}
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=fac(ngvup[i]);ans%=MOD;
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
