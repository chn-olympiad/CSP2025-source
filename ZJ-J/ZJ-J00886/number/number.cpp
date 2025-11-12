#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		char ch=s[i];
		if(ch>='0' && ch<='9') a[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}