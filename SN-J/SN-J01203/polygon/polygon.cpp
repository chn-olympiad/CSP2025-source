#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		int num=0;
		for(int j=1;j<=i;j++){
			num+=a[j];
		}
		if(num>2*a[n]){
			ans++;
		}
	}
	cout<<ans%998244353;
}
