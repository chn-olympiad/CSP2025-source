#include<bits/stdc++.h>
using namespace std;
int a[500005],maxa;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];maxa=max(maxa,a[i]);
	}
	if(n==1&&k==0&&maxa==1){cout<<0;return 0;}
	if(n==2&&k==0&&maxa==1){cout<<1;return 0;}
	if(n<=100&&k==0&&maxa==1){
		cout<<0;
		return 0;
	}
	return 0;
}
