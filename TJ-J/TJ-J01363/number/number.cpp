#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1000000];
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<a[i];
	}
	return 0;
} 
