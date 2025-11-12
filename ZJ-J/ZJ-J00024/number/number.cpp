#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll g=1;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[g]=0;
			g++;
		}
		if(s[i]=='1'){
			a[g]=1;
			g++;
		}
		if(s[i]=='2'){
			a[g]=2;
			g++;
		}
		if(s[i]=='3'){
			a[g]=3;
			g++;
		}
		if(s[i]=='4'){
			a[g]=4;
			g++;
		}
		if(s[i]=='5'){
			a[g]=5;
			g++;
		}
		if(s[i]=='6'){
			a[g]=6;
			g++;
		}
		if(s[i]=='7'){
			a[g]=7;
			g++;
		}
		if(s[i]=='8'){
			a[g]=8;
			g++;
		}
		if(s[i]=='9'){
			a[g]=9;
			g++;
		}
	}
	sort(a+1,a+g+1);
	for(ll i=g;i>=2;i--){
		cout<<a[i];
	}
	return 0;
}
