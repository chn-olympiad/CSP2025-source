#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s[1000001];
	string a[1000001];
	string c[1000001];
	for(int i=0;i<1000001;i++){
		cin>>s[i];
	}
	for(int i=0;i<1000001;i++){
		if(i>48&&i<58){
			for(int j=0;j<1000001;j++){
				s[i]=c[j];
			}
		}
	}
	string max=0;
	for(int i=0;i<1000001;i++){
		for(int j=0;j<1000001;j++){
			if(c[j]>max){
				max=c[j];
				c[j]=a[i];
				c[j]=' ';
			}
		}
	}
	for(int i=0;i<1000001;i++){
		cin>>a[i];
	}
	return 0;
}
