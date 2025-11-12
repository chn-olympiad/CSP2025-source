#include<bits/stdc++.h>
using namespace std;

long long a[10];

string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	
	string ans = "";
	for(long long i=9;i>=0;i--){
		while(a[i]--){
			ans += i+'0';
		}
	}
	
	cout<<ans;
	return 0;
} 
