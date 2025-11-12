#include <bits/stdc++.h>
using namespace std;
int n,a[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopem("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1]) cout<<1;
		else cout<<0;
	}
	else cout<<2*n-1;
	return 0;
}
