#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r","srdin");
//	freopen("number.out","w","srdout");
	string s;
	getline(cin,s);
	int a[510000];
	int n=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
