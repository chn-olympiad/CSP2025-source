#include<bits/stdc++.h>
using namespace std;
long long x,n,m,sum;
string st;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	st=" "+st;
//	for(int i=1;i<=n;i++) if(st[i]=='0') f[i]++;
//	for(int i=1;i<=n;i++) f[i]=f[i]+f[i-1];
//	for(int i=1;i<=n;i++){
//		cin>>x;
//		for(int j=1;j<=n;j++){
//			if(f[i]>x){
//				k[i-1]++;
//				break;
//			}
//		}
//	}
//	for(int i=m;i<=n;i++){
//		t=1;sum=0;T=0
//		for(int j=1;j<=n;j++){
//			if(T==i) break;
//			if(k[i]>t){
//				long long suma=1,sumb=1;
//				for(int l=k[i];l>=k[i]-t+1;l--) suma*=l;
//				for(int l=1;l<=t;l++) sumb*=l;
//				
//			}
//			else t-=k[i];
//		}
//		if(t==i) ans=(ans+sum)%MOD;
//	}
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	for(int i=m;i<=n;i++){
		long long suma=1,sumb=1;
		for(int j=n;j>=n-m+1;j--) suma=(suma*j)%998244353;
		for(int j=1;j<=m;j++) sumb=(sumb*j)%998244353;
		sum=(sum+suma/sumb)%998244353;
	}
	cout<<sum%998244353;
	return 0;
}