#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	} if(n==3&&max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]) cout<<1;
	else if(n<3)cout<<0;
	else{long long mm=0;
		for(int i=3;i<=n;i++){
			long long num=1;
			int x=n;
			long long nu=1;
			for(int j=1;j<=i;j++){
				num*=x;x--;
				num=num%998244353;
				nu*=j;
				nu=nu%998224353;
			}mm+=num/nu;
			mm=mm%998244353;
		}cout<<mm;
		
		
		
	}return 0;
	 
} 
