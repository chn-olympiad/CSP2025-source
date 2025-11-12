#include<bits/stdc++.h>
using namespace std;
int a[5005],maxa;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,bs=3;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2])))
			cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxa==1){
		cout<<(3+n)*(n-2)/2;return 0;
	}
	return 0;
}
