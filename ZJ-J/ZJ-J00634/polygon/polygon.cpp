#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	if(n==3){
		int m=max(a[0],max(a[1],a[2]));
		int s=a[0]+a[1]+a[2];
		if(s>m)cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
