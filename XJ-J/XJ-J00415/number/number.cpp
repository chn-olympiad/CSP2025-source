#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string a;
	getline(cin,s);
	long long n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
			n++;
		}
	}
	while(n--){
		for(int i=0;i<a.size();i++){
			if(a[i]<a[i+1]){
				int m=0;
				m=a[i];
				a[i]=a[i+1];
				a[i+1]=m;
			}
		}
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
} 
