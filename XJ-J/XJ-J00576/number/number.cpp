#include<bits/stdc++.h>
using namespace std;
string s,a;
int n;
char t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			if(a[j]<a[j+1]){
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			}
		}
	}
	cout<<a;
	return 0;
} 

