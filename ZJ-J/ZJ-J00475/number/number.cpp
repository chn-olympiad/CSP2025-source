#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+500;
string s;
char a[N],j=0;
bool cmp(char x,char y) {
	return x-'0'>y-'0';
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0; i<s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(ll i=0; i<j; i++) {
		cout<<a[i];
	}
	return 0;
}
