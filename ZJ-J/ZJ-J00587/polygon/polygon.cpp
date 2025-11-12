#include<bits/stdc++.h>
using namespace std;

long long n,a[5005],ans;

void p(){
	long long m=1;
	for(int i=2;i<=n;i++) {
		m=(m<<1)+1;
	}
	for(int i=7;i<=m;i++){
		long long k=i,j=1,s=0,da=0;
		while(k){
			if(k%2){
				s+=a[j];
				da=max(da,a[j]);
			}
			j++;k=k>>1;
		}
		if(s>da*2) ans++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(n<400){
		sort(a+1,a+n+1);
		p();	
	}
	else{
		for(int i=0;i<=n-3;i++){
			int o=1,p=1;
			for(int j=1;j<=i;j++) {
				o=o*(n-j+1)%998244353;
				p=p*j%998244353;
			}
			ans=(ans+o/p)%998244353;
		}
	}
	cout<<ans%998244353;
	
	return 0;
}
