#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	int a[100000];
	for(int i=0;i<s.size();i++){
		int c =s[i]-'0';
		if(c>=0 && c<=9) {
			a[k] =c;
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--) {
		cout<<a[i];
	}
	return 0;
}
