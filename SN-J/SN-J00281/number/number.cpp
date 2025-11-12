#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	int n=1;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<'a'){
			n=int(str[i])-'0';
			a[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
