#include<bits/stdc++.h>
using namespace std;
string str;
string a[15];
int b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[int(str[i]-'0')]+=str[i];
		}
	}
	bool f=1;
	for(int i=9;i>=1;i--){
		if(a[i]!=""){
			cout<<a[i];
			f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	cout<<a[0];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
