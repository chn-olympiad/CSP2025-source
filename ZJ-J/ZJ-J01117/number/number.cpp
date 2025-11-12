#include <bits/stdc++.h>
using namespace std;
string st,s;
int a[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0; i<st.size(); i++) if(48<=st[i] && st[i]<=57) a[st[i]-48]++;
	for(int i=9; i>=0; i--) for(int j=0; j<a[i]; j++) s+=i+48;
	cout<<s;
	return 0;
}
