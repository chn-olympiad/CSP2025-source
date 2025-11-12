#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353,N=6e4+7;
int n,a[N],ans,pre[N];
int yh(int c){
	int ans=0;
	ans+=pow(2,n)-2;
	ans-=n;
	ans-=n*(n-1)/2;
	ans%=MOD;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		cout<<yh(n);
	}
	else if(n<=3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	else{
		for(int i=1;i<=n;i++)pre[i]=a[i]+pre[i-1];
		for(int i=n;i>=3;i--){
			if(a[i]*2>=pre[i])continue;
			else ans+=yh(i);
			ans%=MOD;
		}
		cout<<ans;
	}
	return 0;
}
