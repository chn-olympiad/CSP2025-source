#include<bits/stdc++.h>
#include<string>
using namespace std;
int a[100005];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
    cin>>s;
    for(int i=1;i<=s.length();i++){
        if(s=="0"){
        	a[i]=0;
		}else if(s=="1"){
			a[i]=1;
		}else if(s=="2"){
			a[i]=2;
		}else if(s=="3"){
			a[i]=3;
		}else if(s=="4"){
			a[i]=4;
		}else if(s=="5"){
			a[i]=5;
		}else if(s=="6"){
			a[i]=6;
		}else if(s=="7"){
			a[i]=7;
		}else if(s=="8"){
			a[i]=8;
		}else if(s=="9"){
			a[i]=9;
		}sort(a+1,a+s.length());
		for(int i=1;i<=s.length();i++){
			cout<<a[i];
		}return 0;
 }
 }