#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll a[10]={};
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
} 
