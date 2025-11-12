#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
			if(s[i]>='0' && s[i]<='9'){
				a[i]=s[i]-'0';}	
			else a[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			if(a[i]<a[j] && a[i]>=0){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				
			}
	}}
	for(int i=0;i<s.size();i++){
		if(a[i]>=0){
			cout<<a[i];
		}}
	return 0;
} 
