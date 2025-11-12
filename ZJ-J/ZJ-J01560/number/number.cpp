#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll slenth,a[100010],ct=1,nct,otto[19];
bool cmpp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	slenth=s.size();
	for(ll i=slenth-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			otto[s[i]-'1'+1]++;
			nct++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=otto[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
