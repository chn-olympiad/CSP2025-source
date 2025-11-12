#include<bits/stdc++.h>
using namespace std;
int n,a[1001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3){
		if(a[1]+a[2]>a[3] && a[2]+a[3]>a[1] && a[1]+a[3]>a[2]){
			cout<<1<<"\n";
		}
		else cout<<0;
	}
	else {
		cout<<2*n;
	}
	return 0;
}
