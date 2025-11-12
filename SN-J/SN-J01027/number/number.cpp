#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15];
string s;
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(ll i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			++a[s[i]-'0'];
		}
	}
	for(ll i=9;i>=0;--i){
		while(a[i]){
			putchar(i+'0');
			--a[i];
		}
	}
	return 0;
}
