#include<bits/stdc++.h>
using namespace std;
int c[101],d=0;
int main(){
	string a;
	getline(cin,a);
	char b[101];
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			c[d]=a[i]-'0';
			d++;
		}
	}
	
	sort(c,c+d);
	for(int i=d-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
} 
