#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5010],bkc[5010],ans;
long long check(int x,int nn,long long d){
	if(nn==2){
		long long cnt=0;
		for(int i=1;i<=x-1;i++)
			for(int j=i+1;j<=x;j++){
				if(a[i]+a[j]>d){
					cnt=(cnt+1)%MOD;
				}
			}
		return cnt%MOD;
	}
	long long cnt=0;
	for(int k=nn;k<=x;k++){
		cnt=(cnt+check(k-1,nn-1,d-a[k]))%MOD;
	}
	return cnt%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bkc[1]=1;
	for(int i=2;i<=5000;i++){
		bkc[i]=(bkc[i-1]+i)%MOD;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=1;i<=n-2;i++){
			ans=(ans+(n-2-i+1)*bkc[i])%MOD; 
		}
		cout<<ans%MOD;
		return 0;
	} 
	for(int i=3;i<=n;i++){
		for(int j=2;j<=i-1;j++){
			ans=(ans+check(i-1,j,a[i]))%MOD;
		}
	}
	cout<<ans;
	return 0;
} 
