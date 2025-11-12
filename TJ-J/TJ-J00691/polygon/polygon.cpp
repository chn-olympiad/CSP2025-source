#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans36+;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],f&=(a[i]==1);
	if(f){
		int ans=0;
		for(int i=1;i<=n;i++)
		ans=(ans+fun(i))%mod; 
	}
	return 0;
} 
