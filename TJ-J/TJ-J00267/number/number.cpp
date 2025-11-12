#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
string s[1000000];
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string a;
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]=='9'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='8'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='7'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='6'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='5'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='4'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='3'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='2'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='1'){
			cout<<a[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]=='0'){
			cout<<a[i];
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
