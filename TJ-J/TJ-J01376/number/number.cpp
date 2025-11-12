#include<bits/stdc++.h>
using namespace std;
char s[1000000];
long long  a[1000002];
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s; 
	if(strlen(s)==1){
		cout<<s;
	}else{
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='0'&&s[i]<='9'){
				a[n]=s[i]-'0';
				n++;
			}	
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
