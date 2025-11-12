#include<bits/stdc++.h>
using namespace std;
char s[1000100];
int n,a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-48;
		}
		else if(s[i]<'a'||s[i]>'z') break;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
