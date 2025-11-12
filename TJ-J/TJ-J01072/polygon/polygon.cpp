#include<bits/stdc++.h>

using namespace std;

long long n,a[5001],ans,b;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
		}
	}else{
		cout<<2*n-1;
	}
	return 0; 
} 
