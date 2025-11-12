#include<bits/stdc++.h>
using namespace std;
char s[1000006];
int a[1000006]={0},b[1000006]={0},cnt=0;
int main(){
	freopen("number.in",r ,"stdin");
	freopen("number.out",w ,"stdout");
	cin>>s;
	int l=strlen.s();
	for(int i=0;i<l;i++){
		if(s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9){
			a[i]=s[i];
			cnt++;
		}
	}
	for(int i=0;i<cnt-1;i++){
		for(int j=i;j<cnt;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
