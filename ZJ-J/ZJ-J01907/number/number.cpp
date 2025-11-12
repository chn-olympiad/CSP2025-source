#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll j=0,sum=0;
	for(ll i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+1+j);
	if(a[j]==0) {
		cout<<0;
		return 0;
	}
	for(ll i=j; i>=1; i--) {
		cout<<a[i];
	}
	return 0;
}
