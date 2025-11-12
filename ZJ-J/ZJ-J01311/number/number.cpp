#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[10086];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	for(ll i=0;i<len;i++){
		ll sz=s[i]-'0';
		a[sz]++;
	}
	for(ll i=9;i>=0;i--){
		if(a[i]!=0){
			for(ll j=a[i];j>=1;j--){
				cout<<i;
			}
		}
	}
}