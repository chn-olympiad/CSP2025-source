#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],p,l;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	l=s.size();
	s=" "+s;
	for(int i=1; i<=l; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++p]=s[i]-'0';
		}
	}
	sort(a+1,a+1+p,cmp);
	for(int i=1; i<=p; i++) {
		cout<<a[i];
	}
	return 0;
}