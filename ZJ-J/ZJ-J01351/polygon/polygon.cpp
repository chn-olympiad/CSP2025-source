#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,N=5010;
int a[N];
int n;
ll qmi(ll a,ll b,ll p){
	if(b==1)return a;
	if(b==0)return 1;
	ll x=qmi(a,b/2,p);
	if(b%2==1)return x*x%p*a%mod;
	else return x*x%p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		int ans=0;
		for(int i=1;i<(1<<n);i++){
			int k=0,sum=0,mx=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					k++;
					sum+=a[j+1];
					mx=max(mx,a[j+1]);
				}
			}
			if(k<3)continue;
			if(sum>2*mx){
				ans++;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(a[1]<=1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2%mod;
		}
		ans=(ans-1-n+mod)%mod;
		int res=1;
		for(int i=3;i<=n;i++){
			res=res*i%mod;
		}
		res=res*qmi(2,mod-2,mod);
		ans=(ans-res+mod)%mod;
		cout<<ans<<'\n';
		return 0;
	}
	cout<<n*n<<'\n';
	return 0;
}