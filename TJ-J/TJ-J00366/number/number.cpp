#include <bits/stdc++.h>
using namespace std;

int const N=1000010;
string s;
int c[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin.tie(0);cout.tie(0);
	
	cin>>s;
	s=" "+s;
	int x;
	for (int i=1;i<s.length();i++){
		x=s[i]-'0';
		if (x>=0 && x<=9) c[x]++;
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=c[i];j++) cout<<i;
	}
	
	return 0;
} 
