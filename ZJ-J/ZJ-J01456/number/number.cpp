#include<bits/stdc++.h>
using namespace std;
string s;
int n[12];
string f(string k){
	string m;
	for(int i=0;i<k.length();i++){
		if('0'<=k[i]&&k[i]<='9'){
			m+=k[i];
		}
	}
	return m;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	string m=f(s);
	for(int i=0;i<m.length();i++){
		n[m[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<n[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
