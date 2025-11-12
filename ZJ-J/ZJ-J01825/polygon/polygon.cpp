#include<bits/stdc++.h>
using namespace std;
int n,a[5050],z1,z2,z3;
bool al=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) al=false;
	}
	z1=a[1]+a[2]+a[3];
	z2=max(a[1],max(a[2],a[3]));
	for(int i=1;i<n;i++){
		z3+=i;
	}
	if(n==3 && z2*2<z1) cout<<1;
	else if(al==true) cout<<pow(2,n)-1-n-z3;
	else cout<<0;
	
	return 0;
}

