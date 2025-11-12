#include<bits/stdc++.h>
using namespace std;
string s;
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' and s[i]<='9') {
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
} 
