//SN-J01157 饶子轩 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,s,d;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<=57&&a[i]>=49){
			s[i]=a[i];
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(j==s.size()-1){
			if(s[i]<=s[j+1]){
				d=s[j+1];
				s[j+1]=s[i];
				s[i]=d;
			}
		}
	}
	cout<<s;
	return 0;
}
