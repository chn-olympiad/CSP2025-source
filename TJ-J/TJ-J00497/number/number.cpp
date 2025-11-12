#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s<="9"&&s>="0"){
		if(s[0]>s[1]){
			cout<<s[0]<<s[1];
		}
		else if(s[0]<s[1]){
			cout<<s[1]<<s[0];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
