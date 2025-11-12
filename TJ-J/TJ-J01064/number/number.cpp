#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstdio>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	frepoen("number.out","w",stdout);
	string s;
	cin>>s;
	string a[s.size()],x;
	int n=0;
	for(int i=0;i<=s.size();i++){
		if (int (s[i])>=48 && int (s[i])<=57){
			a[i]=s[i];
			n+=1;
		}
	}
	for (int i=0;i<=n-1;i++){
		for (int j=1;j<=n-i;j++){
			if (a[i]<a[i+j]){
				x=a[i];
				a[i]=a[i+j];
				a[i+j]=x;
			}
		}
	}
	for(int i=0;i<=n+2;i++){
		cout<<a[i];	 
	}
	
	fclose("number.in");
	fclose("number.out");
	return 0;
}
