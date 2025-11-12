#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,cnt,flag;
string conf;
ll num[509],bac[509];
ll stpow(ll n){
	ll sum=1;
	for(ll i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	return sum; 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	flag=1; 
	cin>>n>>m;
	cin>>conf;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		if(conf[i-1]==0){
			flag=0;
		}
	}
	if(flag){
		cout<<stpow(n);
	}
	return 0;
}
