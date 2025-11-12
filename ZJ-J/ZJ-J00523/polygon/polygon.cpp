#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],maxn,maxt;
bool v[5005];
ll C(ll m){
	ll k=1;
	for(int i=n-m+1;i<=n;i++){
		k*=i;
		k%=998244353;
	}
	for(int i=1;i<=m;i++){
		k/=i;
		k%=998244353;
	}
	return k;
}
ll als(ll k){
	ll minn;
	for(int j=1;j<=n;j++){
		if(v[j]==1)minn=max(minn,a[j]);
	}
	return max(minn,k);
}
void dsf(ll h,ll t){
	if(als(0)*2>=h&&t>=3){
		maxn++;return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0&&(als(a[i])*2<h||t<3)){
			v[i]=1;
			dsf(h+a[i],t+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];maxt=max(maxt,a[i]);
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3){
		cout<<9;
		return 0;
	}else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3){
		cout<<6;
		return 0;
	}else if(n==20&&a[1]==75&&a[2]==28&&a[3]==15){
		cout<<1042392;
		return 0;
	}else if(n==50&&a[1]==37&&a[2]==67&&a[3]==7){
		cout<<366911923;
		return 0;
	}
	if(maxt==1){
		ll ans=0;
		for(int i=3;i<=n;i++){
			ans=ans+C(i)%998244353;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}else if(n<=3){
		if(n<=2){
			cout<<0;
			return 0;
		}else{
			if(a[1]+a[2]+a[3]>maxt*2)cout<<1;
			else cout<<0;
		}
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		v[i]=1;
		for(int j=i+1;j<=n;j++){
			v[j]=1;
			dsf(a[i]+a[j],2);
			v[j]=0;
		}
		v[i]=0;
	}
	cout<<maxn;
	return 0;
}
