#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,k;
int a[543210];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m=max(a[1],a[2]);
	int m1=max(m,a[1]^a[2]);
	cout<<m1;
	return 0;
}
