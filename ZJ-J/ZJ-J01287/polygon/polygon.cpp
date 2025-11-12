#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5105];
long long f[5105];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	long long ans=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=a[n]+1;j++){
			ans+=f[j];
			ans%=mod;
		}
		f[a[n]+1]*=2;
		f[a[n]+1]%=mod;
		for(int j=a[n];j>=0;j--){
			if(j+a[i]>a[n]){
				f[a[n]+1]+=f[j];
				f[a[n]+1]%=mod;
			}
			else{
				f[j+a[i]]+=f[j];
				f[j+a[i]]%=mod;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
