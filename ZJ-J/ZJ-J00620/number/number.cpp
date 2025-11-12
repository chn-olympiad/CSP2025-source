#include<bits/stdc++.h>
using namespace std;
string s;
int nu[10];
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')nu[s[i]-'0']++;
	}
	for(int i=10;i>=0;i--){
		for(int j=1;j<=nu[i];j++)cout<<i;
	}
	return 0;
}
