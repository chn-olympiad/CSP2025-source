#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=2){
		cout<<"0";
		return 0;
	}
	int a1,a2,a3;
		if(n==3)	cin>>a1>>a2>>a3;
	
	
	int aa=a1+a2+a3,aaa=max(a1,max(a2,a3));
	aaa=aaa*2;
	if(aa>=aaa){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

