#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll MOD=998244353;
ll n=0,pta=0,a[N]={};
void qwertyuiop(){
	ll pp=n*(n-1)/2;
	pp%=MOD;
	ll res=1;
	for(int i=1;i<=n;i++){
		res<<=1;
		res%=MOD;
	}
	res+=MOD;
	res-=pp;
	res+=MOD;
	res-=n+1;
	res%=MOD;
	cout<<res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			pta=-1;
		}
	}
	if(pta==0){
		qwertyuiop();
		return 0;
	}
	ll ans=0;
	ll cho=0,mx=0,k=0,sum=0;
	for(int i=1;i<=(1<<n)-1;i++){
		cho=0;
		mx=-1;
		k=i;
		sum=0;
		for(int j=1;k;j++){
			if(k&1){
				sum+=a[j];
				mx=max(mx,a[j]);
				cho++;
			}
			k>>=1;
		}
		if(cho>=3&&sum>mx*2)ans++;
	}
	cout<<ans;
	return 0;
}
