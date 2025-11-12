#include <bits/stdc++.h>
using namespace std;
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		int j;
		for(j=0;j<t[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}