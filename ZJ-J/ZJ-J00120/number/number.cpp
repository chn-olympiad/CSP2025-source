#include<bits/stdc++.h>
using namespace std;
string s;
long long mp[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			mp[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<mp[i];j++) printf("%d",i);
	}
	return 0;
}