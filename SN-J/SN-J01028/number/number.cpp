#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string x;
	cin>>s;
	int a[1005],sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='z'&&s[i]>='a'){
			s[i]=' ';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=' '){
			x=x+s[i];
		}
	}
	for(int i=0;i<x.size();i++){
		if(x[i]<x[i+1]){
			sum=x[i];
			x[i]=x[i+1];
			x[i+1]=sum;
		}
	}cout<<x;

	return 0;
}
