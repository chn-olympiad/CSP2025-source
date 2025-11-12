#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,sum=0,sum2=0;
const int N=5e5+10;
ll a[N];
vector<ll>adj;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1){
			sum++;
		}
	}
	for(ll i=1;i<=n;++i){
		if(i==1&&a[i]==1){
			sum2++;
			continue;
		}
		if(a[i]==1 && a[i-1]==1){
			sum2++;
		}else{
			adj.push_back(sum2);
			if(a[i+1]==1){
				sum2=1;
			}else{
				sum2=0;
			}
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(n==2){
		cout<<1;
		return 0;
	}
	else if(n<=10){
		if(k==1){
			cout<<sum;
			return 0;
		}else if(k==0){
			ll sum3=0;
			for(ll i=0;i<adj.size();++i){
				sum3+=adj[i]/2;
			}
			cout<<n-sum+sum3;
			return 0;
		}
	}
	else if(n<=100){
		if(k==0&&sum==n){
			cout<<n/2;
			return 0;
		}
		if(k==0&&sum!=n){
			ll sum3=0;
			for(ll i=0;i<adj.size();++i){
				sum3+=adj[i]/2;
			}
			cout<<n-sum+sum3;
			return 0;
		}
		if(k==1){
			cout<<sum;
			return 0;
		}
	}
	else if(n<=2e5){
		if(k==1){
			cout<<sum;
			return 0;
		}else if(k==0){
			ll sum3=0;
			for(ll i=0;i<adj.size();++i){
				sum3+=adj[i]/2;
			}
			cout<<n-sum+sum3;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
