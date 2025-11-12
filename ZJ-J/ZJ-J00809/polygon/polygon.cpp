#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5005,mod=998244353;
LL qmi(LL x,int y){
	LL ret=1;
	while(y){
		if(y&1) ret=(ret*x)%mod;
		y>>=1,x=(x*x)%mod;
	}
	return ret;
}
int a[N],f[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	LL sum=(qmi(2,n)-1+mod)%mod;
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			sum=(sum-f[j]+mod)%mod;
		}
		for(int j=5000;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
	}
	cout<<sum<<endl;
	return 0;
}
