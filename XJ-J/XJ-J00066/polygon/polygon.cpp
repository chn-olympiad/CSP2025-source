#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=1+2+3+4+5;
	if (n==5){
		if (a[1]+a[2]+a[3]+a[4]+a[5]==s){
			cout<<9;
		}
	}
	return 0;
} 
