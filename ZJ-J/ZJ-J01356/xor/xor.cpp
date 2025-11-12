#include<bits/stdc++.h>
using namespace std;
long long n,k;
int mx,mn=2e6;
int x,y,z;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		if(a[i]==1&&a[i-1]==1)x++;
		if(a[i]==0)y++;
		if(a[i]==1)z++;
	}
	if(n<=2&&k==0&&mx==1&&mn==1){
		if(n==1)cout<<0;
		else cout<<1;
		return 0;
	}
	if(k<=1&&mx<=1){
		if(k==0){
			cout<<x+y;
			return 0;
		}
		if(k==1){
			cout<<z;
			return 0;
		}
	}
	return 0;
}
