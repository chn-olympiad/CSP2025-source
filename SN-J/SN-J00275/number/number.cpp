#include<iostream>
#include<cstring>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,maxn=0,newn=0;
	cin>>s;
	for(int i=0;i<1000;++i){
		if(s[i]==1)
			newn[i]=1;
		if(s[i]==2)
			newn[i]=2;
		if(s[i]==3)
			newn[i]=3;
		if(s[i]==4)
			newn[i]=4;
		if(s[i]==5)
			newn[i]=5;
		if(s[i]==6)
			newn[i]=6;
		if(s[i]==7)
			newn[i]=7;
		if(s[i]==8)
			newn[i]=8;
		if(s[i]==9)
			newn[i]=9;
		if(s[i]==0)
			newn[i]=0;
	}
	for(int i=0;i<1000;++i){
		if(maxn>newn){
			maxn=newn;
		}
	}
	return 0;
}
