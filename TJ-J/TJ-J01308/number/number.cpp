#include <bits/stdc++.h>
using namespace std;

int b;
string a;

int main(){
	cin>>a;
	int s[a.size()+5]={};
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			s[b]=a[i]-'0';
			b++;	
		} 
	}
	
	sort(s,s+a.size());
	
	for(int i=a.size()+4;i>=a.size()-b+5;i--){
		cout<<s[i];
	}
	
	return 0;
}
