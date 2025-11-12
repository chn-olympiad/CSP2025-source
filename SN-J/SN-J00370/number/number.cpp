#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool f=true;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&'0'<=s[i]){
			a[s[i]-'0']++;
			if(s[i]-'0'!=0){
				f=false;
			}
		}
	}
	if(f){
		cout<<0;
	}else{
		for(int i=9;i>=0;i--){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
