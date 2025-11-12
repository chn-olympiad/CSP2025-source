#include<bits/stdc++.h>
using namespace std;
string str;
int st[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		char c=str[i];
		if(c>='0'&&c<='9')st[c-'0']++;
 	}
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=st[i];j++){
			cout<<i;
		}
	}
	return 0;
}
