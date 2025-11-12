#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,a[5005],ma=-1,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=3;i<=n;i++){
		int sh=1,xia=1;
		for(int j=n;j>n-i;j--){
			sh*=j;
		}
		for(int j=1;j<=i;j++){
			xia*=j;
		}
		cnt=sh/xia;
	}*/
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*a[k] && a[i]+a[k]+a[j]>2*a[j] && a[j]+a[k]+a[i]>2*a[i]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt%(998244353);
	return 0;
} 
