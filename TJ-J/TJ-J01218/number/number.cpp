#include<bits/stdc++.h>
using namespace std;
long long l[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			l[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=l[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
