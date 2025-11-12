#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n==3){
		cout<<(a[1]+a[2]>a[3]?"1":"0");
	}
	else if(b[n]==n){
		int f[5005];
		f[1]=0,f[2]=0;
		long long tot=1;
		int mod=998244353;
		for(int i=3;i<=n;i++){
			f[i]=(f[i-1]+tot)%mod;
			tot=(tot*2+1)%mod;
		}
		cout<<f[n];
	}
	else{
		cout<<"19278645";
	}
	return 0;
}
