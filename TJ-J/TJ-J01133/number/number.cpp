#include <bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int n[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(int('0')<=int(s[i])and int(s[i])<=int('9')){
			n[cnt]=int(s[i])-48;
			cnt+=1;
		}
	}
	sort(n,n+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
