#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll a[12],ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k = s.size();
	for(ll i = 0;i<k;i++){
		if(s[i] >= '0' and s[i] <= '9'){
			ll n = int(s[i]) - 48;
			a[n]++;
		}
	}
	for(ll i = 9;i>=0;i--){
		while(a[i]>0){
			ans = ans*10+i;
			a[i]--;
		}
	}
	cout<<ans;	
	return 0;
}
