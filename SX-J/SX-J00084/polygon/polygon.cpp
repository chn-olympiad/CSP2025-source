#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ma,v,k,c;
int a[5005],s[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=3;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		v+=a[i];
	}
	if(v>ma*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}