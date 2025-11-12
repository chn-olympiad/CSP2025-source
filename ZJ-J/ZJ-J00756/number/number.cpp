#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll n=s.size();
	string ss="";
	for(ll i=9;i>=0;i--){
		for(ll j=0;j<n;j++){
			if(s[j]-'0'==i){
				ss=ss+s[j];
			}
		}
	}cout<<ss;
	return 0;
}

