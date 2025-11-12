#include<iostream>
#define ll long long
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	bool flag=1;
	for(char ch:s){
		if(ch!='0'){
			flag=0;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	ll ans=1;
	for(int i=2;i<=n;i++){
		ll ans1=ans;
		for(int j=1;j<i;j++){
			ans+=ans1;
			if(ans>mod){
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
