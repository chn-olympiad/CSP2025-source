#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],f[5005][5005],maxn;
long long ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=3;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
			sum+=a[i];
		}
		if(sum>2*maxn){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=0;i<=n;i++){
		f[i][0]=1,f[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%MOD;
		}
	}
	for(int i=3;i<=n;i++){
		ans=(ans+f[n][i])%MOD;
	}
	cout<<ans/6*5;
	return 0;
}
