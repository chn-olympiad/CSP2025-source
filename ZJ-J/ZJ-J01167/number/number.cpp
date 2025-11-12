#include<bits/stdc++.h>
using namespace std;
string s,a;
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
			n++;
		}
	}
	for(int i=0;i<=a.length();i++){
		for(int j=0;j<a.length();j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	cout<<a;
	return 0;
}
