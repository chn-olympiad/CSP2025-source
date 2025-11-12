#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	long long sum=0;
	for(int j=1;j<=n-3+1;j++){
		for(int k=j+1;k<=n-j;k++){
			for(int l=k+1;l<=n;l++){
				if(a[j]+a[k]+a[l]>2*a[l]){
					sum=(sum+1)%998244353;
					break;
				}
			}
		}
	}cout<<sum;
	return 0;
}
