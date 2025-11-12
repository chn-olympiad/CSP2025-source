#include<bits/stdc++.h>
using namespace std;
int a[10001],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=max(a[0],max(a[1],a[2]));
	if(a[0]+a[1]+a[2]>2*l) cout<<1;
	else cout<<0;
}

