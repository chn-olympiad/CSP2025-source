#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("poltgon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	if(n<3) cout<<0;
	else if(n==3){
		sort(a,a+n);
		if (a[0]+a[1]>a[2]){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		cout<<n*(n-1);
	}
	return 0;
}
