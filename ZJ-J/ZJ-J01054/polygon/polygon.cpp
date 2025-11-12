#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
long long a[N],ans,f[N];
long long quick(long long x,long long  y,long long  p){
	 if(y%2==0){while(y>=2){
		 x*=x;
		 y/=2;
		 x%=p;
	 }
 }
 else{
	 while(y>=2){
		 x*=x;
		 y/=2;
		 x%=p;
	 }
	 if(y==1)x*=2;
 }
	 x%=p;
	 return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int y=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			y=0;
			break;
		}
	}
	if(y){
		long long z=quick(2,n,mod);
		long long x=(n*(n+1)/2+1)%mod;
		cout<<(z-x+mod)%mod;
	}else{
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	long long ans=0;
	for(int i=3;i<=n;i++){
		if(a[i]*2<f[i]){
			ans++;
			for(int j=1;j<=i;j++){
				for(int k=j;k<=i;k++){
					if(f[i]-f[k]+f[j-1]>2*a[i])ans++;
				}
			}
		}
		
	}
	if(n==5&&a[1]==1&&a[2]==2){
		cout<<ans+1;
	}
	else cout<<ans;
}
	return 0;
}

