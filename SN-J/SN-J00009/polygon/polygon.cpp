#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=(n*n-n)/2-1;
	printf("%lld",sum);
	return 0;
}
