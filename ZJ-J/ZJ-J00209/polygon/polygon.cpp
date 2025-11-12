#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxx,sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx) maxx=a[i];
		sum+=a[i];
	}
	if(n<=3){
		if(sum>maxx*2) cout<<1;
		else cout<<0;
	}
	else if(maxx<=1){
		cnt=(1+n)%998244353;
		for(int i=1;i<=n-4;i++){
			for(int j=2;j<=n-2+i;j++){
				cnt+=j;
				cnt%=998244353;
			}
		}
		cout<<cnt;
	}
	return 0;
}
