#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]-'0'<10&&s[i]-'0'>=0)a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)cout<<i;
	}
	return 0;
} 
