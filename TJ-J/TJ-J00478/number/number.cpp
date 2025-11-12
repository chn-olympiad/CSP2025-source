#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005]={'0'};
	int ans=0,cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='9'||s[i]=='7'||s[i]=='6'||s[i]=='5'||s[i]=='4'||s[i]=='3'||s[i]=='2'||s[i]=='1'||s[i]=='8'){
			cnt++;
			a[cnt]=s[i];
		}
	}
for(int i=1;i<=cnt;i++){
		if(a[i]=='9'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='8'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='7'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='6'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='5'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='4'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='3'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='2'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='1'){
		cout<<a[i];
	}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]=='0'){
		cout<<a[i];
	}
	}
	
	return 0;
} 
