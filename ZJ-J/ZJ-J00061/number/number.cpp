#include<bits/stdc++.h>
using namespace std;
long long int b[10],a=0,c=0,d=0;
char s[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]<='9'&&s[i]>='0'){b[s[i]-'0']+=1;a++;}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}	
	}
	return 0;
}
