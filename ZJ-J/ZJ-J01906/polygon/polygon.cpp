#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5100],f[5100],ans,sum;
void _01dp_He_Jingtian_give_me_100_point_please_I_AK_CJ(int x){
	sum+=sum;
	sum%=mod;
	for(int i=5000;i>=0;--i){
		if(i+a[x]>5000){
			sum+=f[i];
			sum%=mod;
		}
		else{
			f[i+a[x]]+=f[i];
			f[i+a[x]]%=mod;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<n;++i){
		_01dp_He_Jingtian_give_me_100_point_please_I_AK_CJ(i);
		if(i>=2){
			ans+=sum;
			ans%=mod;
			for(int j=a[i+1]+1;j<=5000;++j){
				ans+=f[j];
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
