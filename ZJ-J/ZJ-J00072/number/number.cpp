#include<bits/stdc++.h>
using namespace std;
char s[1000005];
string num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))num[s[i]-'0']+=s[i];
	}
	for(int i=9;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
