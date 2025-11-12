#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod=998244353;
LL f[(1<<18)][19];
int n,m,c[20];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n>20){
		LL ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++)cin>>c[i];
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			sum++;
		}
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			for(int k=0;k<=n;k++){
				if(s[sum]=='0'||sum-k>c[j]){
					f[i][k]+=f[(i^(1<<j))][k];
					f[i][k]%=mod;
				}else if(k!=0){
					f[i][k]+=f[(i^(1<<j))][k-1];
					f[i][k]%=mod;
				}
			}
		}
	}
	LL ans=0;
	for(int i=m;i<=n;i++){
		ans+=f[(1<<n)-1][i];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
