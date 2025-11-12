#include<bits/stdc++.h>
using namespace std;
long long n,a[5000],sum,gc1=1,gc2=2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		gc1*=(i+1);
	}
	sort(a,a+n);
	if(n==3){
			if(a[0]+a[1]>a[2]&&a[2]+a[1]>a[0]&&a[2]+a[1]>a[1])cout<<1;
			else cout<<0;

	}
	else {
		for(int i=3;i<=n;i++){
			gc2*=i;
			sum+=(gc1/gc2);

		}cout<<sum;
	}
}



