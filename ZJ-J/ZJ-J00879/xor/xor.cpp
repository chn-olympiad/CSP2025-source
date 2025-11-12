#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
int n,k,a[N],b[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(k==0){
		ans=n/2;
	}if(k==1){
		for(int i=1;i<n;i++){
			if(a[i]+a[i+1]==1) ans++;
		}
	}
	cout<<ans;
	return 0;
}