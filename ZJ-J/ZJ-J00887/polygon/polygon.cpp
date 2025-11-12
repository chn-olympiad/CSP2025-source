#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans=0;
int a[5005];

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[3]){
		ans=1;
	}
	cout<<ans;
	return 0;
}