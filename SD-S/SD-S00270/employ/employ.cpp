#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m;
const ll MOD=998244353;
ll jc(ll x){
	ll num=1;
	for(int i=2;i<=x;i++){
		num=(num*x)%MOD;
	}
	return num;
}
ll a[1000006],sum=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		string s;
		cin>>s;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<s.size();i++){
			if(s[i]!='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}else{
		string s;
		cin>>s;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			if(a[i]==0) sum++;
		}
		if(n-sum<m) cout<<0;
		else{
			cout<<jc(n)%MOD;
		}
	}
	return 0;
}

