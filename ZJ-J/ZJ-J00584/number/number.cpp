#include<bits/stdc++.h>
using namespace std;
int tong[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' and s[i]<='9')tong[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++)cout<<i;
	}
	return 0;
}
