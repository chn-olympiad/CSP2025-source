#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",studio);
	freopen("number.out","w",std);
	int a[100000];
	string s;
	cin>>s;
	int m=0;
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=0+48&&int(s[i])<=9+48){
			a[m]=s[i]-48;
			m++; 
		}
	}
	for(int x=0;x<m;x++){
		for(int y=0;y<m;y++){
			if(a[y]<=a[x]){
				int c=a[y];
				a[y]=a[x];
				a[x]=c;
			}
		} 
	}
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	return 0;
} 
