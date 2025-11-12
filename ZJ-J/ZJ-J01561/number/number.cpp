#include<bits/stdc++.h>
using namespace std;
map<char,int>a;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		a[s[i]]++;
	}
	for(int i='9';i>='0';i--){
		for(int j=1;j<=a[i];j++){
			printf("%c",(char)i);
		}
	}
}