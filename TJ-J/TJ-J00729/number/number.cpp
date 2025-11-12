#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int x=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'|s[i]=='9'){
			a[x]=int(s[i])-48;
			x++;
		}
	}
	sort(a+1,a+x,cmp);
	for(int i=1;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
