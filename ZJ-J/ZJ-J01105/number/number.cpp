#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string num;
	cin>>num;
	for(ll i=0;i<num.size();i++){
		if(num[i]>='0'&&num[i]<='9'){
			a[num[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}

