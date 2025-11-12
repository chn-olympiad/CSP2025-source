#include<bits/stdc++.h>
using namespace std;
int n,q;
struct str {
	string s1,s2;
} s[200005];
string kmp(string a,string b,string c) {
	bool book=1;
	string st;
	int lena=a.size(),lenb=b.size();
	for(int i=0; i<lena; i++) {
		bool key=0;
		for(int j=0; j<lenb; j++)
			if(a[i+j]!=b[j]) {
				key=1;
				break;
			}
		if(key)continue;
		for(int j=0; j<i; j++)st+=a[j];
		st+=c;
		for(int j=i+lenb; j<lena; j++)st+=a[j];
		book=0;
		break;
	}
	if(book)return a;
	return st;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)cin>>s[i].s1>>s[i].s2;
	while(q--) {
		int ans=0;
		string t,t1,t2;
		cin>>t1>>t2;
		for(int i=1; i<=n; i++) {
			t=kmp(t1,s[i].s1,s[i].s2);
			if(t==t2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

