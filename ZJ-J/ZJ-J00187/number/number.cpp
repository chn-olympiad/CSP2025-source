#include<bits/stdc++.h>
using namespace std;
string s;
int k[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9')
			k[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	for(int j=k[i];j>=1;j--)
		printf("%d",i);
	return 0;
}