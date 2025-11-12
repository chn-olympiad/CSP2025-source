#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll gx[114];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(isdigit(s[i])){
			gx[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=gx[i];j++){
			cout<<i;
		}
	}
	return 0;
}
