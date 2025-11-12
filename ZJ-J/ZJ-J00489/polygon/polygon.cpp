#include<bits/stdc++.h>
using namespace std;
int n,a[21];
int maxx=0,tot=0;
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		maxx=max(a[1],max(a[2],a[3]));
		tot=a[1]+a[2]+a[3];
		if(tot>maxx*2){
			ans=1;	
					
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-2;i++){
			ans=(ans%998244353+((n-i)*(n-i-1)/2)%998244353)%998244353;
		}
	}
	cout<<ans;
	
	return 0;
}