#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
int n[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[x]=s[i];
			x++;
		}
	}
	for(int i=0;i<x;i++){
		n[i]=int(a[i])-'0';
	}
	sort(n,n+x);
	for(int i=x-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
