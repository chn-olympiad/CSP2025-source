//I really want to get 2= or 1=
//16pts? 
//sum=80+16+10+5=119pts?
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define ull unsigned long long
int n,m;
string s;
const ull mod=998244353;
bool flagA=1;
ull spow(ull a){
	ull res=1;
	while(a){
		res*=a;
		res%=mod; 
		a--;
	}
	return res;
}
int cnt1=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') flagA=0;
		else cnt1++;
	}
	if(cnt1<m){
		cout<<0;
		return 0;
	}
	if(flagA){
		cout<<spow(n);
	}
	return 0;
}
