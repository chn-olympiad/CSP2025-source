#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s="";
char c[1000005]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int ws=s.size();
	for(int i=0;i<ws;i++){
		if(s[i]<='9'&&s[i]>='0'){
			c[i]=s[i];
		}
 }
	sort(c,c+ws);
	for(int i=ws-1;i>=0;i--){
		if(c[i]>='0'&&c[i]<='9'){
				cout<<c[i];
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
