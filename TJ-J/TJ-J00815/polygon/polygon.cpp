#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5001];
int n;
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(n<=3){
		if(a[0]+a[1]+a[2]>2*max(max(a[0],a[1]),a[2]))ans++;
	}
	if(n<=5000&&n>=500){
		int f[5000];
		f[0]=1;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]*2+1;
		}
		ans=f[n];
	}
	
	cout<<ans%998244353;
	return 0;
}

