#include<bits/stdc++.h>
using namespace std;
long long t[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[int(s[i])-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]--){
			cout<<i;
		}
	}
	return 0;
}
