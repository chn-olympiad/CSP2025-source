#include<bits/stdc++.h>
using namespace std;

string s;
string sum[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			sum[s[i]-'0']+=s[i];
		}
	}
	for(int i=9;i>=0;i--){
		if(sum[i].size()!=0) cout<<sum[i];
	}
	return 0;
} 
