#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p=998244353,f,u,mx,ans;
ll a[5010],s[5010];
ll qp(ll a,ll b){
	ll res=1;
	while(b!=0){
		if(b%2==1){
			res=res*a%p;
		}
		b/=2;
		a=a*a%p;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1]){
			f=1;
		}
	}
	if(f){
	}else{
		for(int i=1;i<=n;i++){
			u+=i;
		}
		cout<<qp(2,n)-u-1;
	}
	return 0;
}

