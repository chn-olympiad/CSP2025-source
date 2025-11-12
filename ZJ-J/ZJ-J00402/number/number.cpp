#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll b[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool d=0;
	string a;
	cin>>a;
	for(ll i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(ll i=9;i>-1;i--){
		for(ll j=1;j<=b[i];j++){
			cout<<i;
			d=1;
		}
	}
	return 0;
}
