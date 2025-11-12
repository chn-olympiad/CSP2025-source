#include<bits/stdc++.h>
using namespace std;
#define mod 998244353;
int n,t,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		int m=1<<(n-(n-i+1));
		for(int j=3;j<m;j++){
			int f=j,z=0,zt=0;
			for(int k=0;f!=0;k++){
				zt=k;
				if(f%2==1) z+=a[k];
				f=f/2;
			}
			if(zt<2) continue;
			if(z>i) t++;
			t=t%mod;
		}
	}
	cout<<t;
	return 0;
}
