#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,ori;
int a[10000001];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ori=1;
		}
	}
	sort(a+1,a+1+n);
	if(ori==1){
		if(n==3){
			if(a[i-2]+a[i-1]+a[i]>2*a[i]){
				ans++;
			}
			cout<<ans<<endl;
		}	
	}
	return 0;
}
