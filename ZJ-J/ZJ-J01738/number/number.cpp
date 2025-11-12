#include<bits/stdc++.h>
using namespace std;
char s[1001000];
int len,i,t,f[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	len=strlen(s+1);
	for(i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-48]++;
		}
	}
	for(i=9;i>=0;i--){
		while(f[i]--){
			cout<<i;
		}
	}
	return 0;
}
