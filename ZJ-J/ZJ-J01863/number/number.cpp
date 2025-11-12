#include<bits/stdc++.h>
using namespace std;
char s[1111111];
int t,b[1111111];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		int a=s[i]-'0';
		if(a>=0&&a<=9){
			b[++t]=a;
		}
	}	
	sort(b+1,b+t+1);
	for(int i=t;i>=1;i--){
		cout<<b[i];
	}
} 
