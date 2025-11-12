#include<bits/stdc++.h>
using namespace std;
long long hash[100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			hash[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(hash[i]>0){
			cout<<i;
			hash[i]--;
		}
	}
	return 0;
} 
