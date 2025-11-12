#include<bits/stdc++.h>
using namespace std;
string s;
int bas[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			bas[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(bas[i]--){
			cout<<i;
		}
	}
	return 0;
}