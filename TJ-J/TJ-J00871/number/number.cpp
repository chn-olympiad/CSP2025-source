#include<bits/stdc++.h>
using namespace std;
int a[130];
string s;
bool isnm(char x){
	if('0'<=x&&x<='9') return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'&&isnm(s[i])) flag=false;
		a[s[i]]++;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=57;i>=48;i--){
		for(int j=1;j<=a[i];j++){
			cout<<char(i);
		}
	}
	return 0;
}
