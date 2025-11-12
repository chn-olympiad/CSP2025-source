#include<bits/stdc++.h>
using namespace std;
int len(string s);
int main(){
	string s;
	//freopen("number.in","w");
	//freopen("number.out","r");
	int a[100];
	cin>>s;
	int t=100;
	int j=0;
	for(int i=0;i<=t;i++){
		if(s[i]<'a'){
			a[j]=s[i];
			j+=1; 
		}
	}
	sort(a+1,t);
	for(int i=0;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
