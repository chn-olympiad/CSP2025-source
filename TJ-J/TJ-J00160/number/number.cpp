#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000000];
char s[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int f=0;
	for(int i=0;int(s[i])!=0;i++){
		if(int(s[i])>=48 && int(s[i])<=57){
			a[f]=int(s[i]);
			a[f]-48;
			f++;
		}
	}
	for(int i=11;i>=0;i--){
		for(int j=0;j<f;j++){
			if(i<=a[j]){
				cout<<a[j];
			}
		}
	}
	return 0;
}
