#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001],b[1000001],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;	
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int d=1;d<=(1ll<<n);d++){
		int t=d,cnt=0,k=0,maxx=0;
		while(t){
			if(t&1==1){
				b[++k]=a[n-cnt];
			}
			t>>=1;
			cnt++;
		}
		int num=0;
		for(int i=1;i<=k;i++){
			num+=b[i];
			maxx=max(maxx,b[i]);
		}
		if(num>maxx*2) ans++;
	}
	cout<<ans;
	return 0;
}
