#include<bits/stdc++.h>
#define ll long long
#define itn int
using namespace std;
ll n,a[5005],ans = 0;

void ck(itn mx,itn sm,itn x){
	if(x==0) {
		if(sm>mx) ans++;
		return ;
	}
	ck(mx,sm+a[x],x-1);
	ck(mx,sm,x-1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(itn i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(itn i=1;i<=n;i++){
		itn mx = a[i]*2,sum=a[i];
		ck(mx,sum,i-1);
	}
	cout<<ans%998244353;
	return 0;
}
