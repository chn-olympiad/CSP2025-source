#include <bits/stdc++.h>
using namespace std;
string s;
int l_a[1000010];
bool l_cmp(int a,int b) {
	return a>=b;	
}
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i< s.size();++i) {
		l_a[i] = int (s[i]);
	}
	sort(l_a,l_a+s.size(),l_cmp);
	for (int i=0;i<s.size();++i) {
		if (l_a[i]>=47 && l_a[i]<=57) {
			cout<< l_a[i]-48;
		}
	}
	return  0;
}

