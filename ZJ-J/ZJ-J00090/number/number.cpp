#include<bits/stdc++.h>
using namespace std;
string s;int tong[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			tong[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=tong[i];j>=1;j--)
			cout<<i;
	}
	return 0;
}