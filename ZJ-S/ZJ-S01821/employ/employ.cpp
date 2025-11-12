#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, c[505];
string str;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for(ll i=1; i<=n; i++)cin >> c[i];
	if(m==n){
		bool flag=1;
		for(ll i=0; i<str.size(); i++){
			flag|=(str[i]-'0')^1;
		}
		cout<<flag;
	}
	else{
		ll fir=0;
		for(ll i=0; i<n; i++){
			fir++;
			if(str[i]=='0')break;
		}
		ll sum=0;
		for(ll i=1; i<=n; i++){
			sum+=(c[i]>=fir);
		}
		for(ll i=1; i<n; i++)sum=sum*i%998244353;
		cout<<sum;
	}
	return 0;
}
//4·Ö+(12·Ö)?
