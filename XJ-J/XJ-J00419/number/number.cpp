#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int a[1000000]={0};
int b[1000000]={0};
int main(){
	int cnt=0;
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;

	for(int i=0;i<strlen(s);i++){
		a[cnt]=s[i];
		cnt++;
				
			
	}
	for(int i=0;i<strlen(s);i++){
		b[a[i]]++;
	}
	

	for(int i=9;i>=0;i--){
		if(b[i]!=0){
			for(int j=0;j<b[i];j++)
				cout<<i;
		}
	}
	return 0;
} 
