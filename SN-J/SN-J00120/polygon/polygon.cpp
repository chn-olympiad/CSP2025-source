#include <bits/stdc++.h> 
using namespace std;
const int mod=998244353;
int n,m;
int a[5005];
long long ans;
long long C(int n,int i){
	if(i==1) return n;
	return n*C(n-1,i-1)/i;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>m) m=a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(m==1){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])){
						ans++;
						for(int e=1;e<=n-3;e++){
							ans=(ans+C(n-3,e))%mod;
						}
					}
				}
			}
		}
		cout<<ans/4*3;
	}
	return 0;
}
