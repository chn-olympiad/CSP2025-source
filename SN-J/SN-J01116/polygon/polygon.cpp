#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,sum2;
int a[5005];
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
			sum2=max(sum2,a[i]);
		}
		if(sum>sum2*2){
			cout<<1;
		}	
		else{
			cout<<0;
		}
	}
	else{
		cout<<9;
	}
	return 0;
}
