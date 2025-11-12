#include<bits/stdc++.h>
using namespace std;
int n,a[11451],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		sort(a,a+2);
		
	if(a[2]*2<a[0]+a[1]+a[2]) cout<<1;
	else cout<<0;
	return 0;
}
