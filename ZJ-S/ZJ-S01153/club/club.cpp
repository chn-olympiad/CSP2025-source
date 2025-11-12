#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n;
int a[1000005],b[1000005],c[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+n+1);
		ll ans=0;
		for(int i=n;i>=n/2;i--) ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
