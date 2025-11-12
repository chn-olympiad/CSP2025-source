#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000000+10];
ll m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.length();i++){
		if(isdigit(s[i])){
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+m,greater<ll>());
	for(ll i=0;i<m;i++){
		cout<<a[i];
	}
	return 0;
}
