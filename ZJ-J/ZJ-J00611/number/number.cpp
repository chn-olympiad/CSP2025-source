#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[205];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9');
		a[s[i]]++;
	}
	for(int i='9';i>='0';i--){
		while(a[i]){
			cout<<(char)i;
			a[i]--;
		}
	}
}
