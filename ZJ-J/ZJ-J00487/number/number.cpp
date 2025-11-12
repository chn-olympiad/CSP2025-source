#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(isdigit(i)){
			t[i-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
