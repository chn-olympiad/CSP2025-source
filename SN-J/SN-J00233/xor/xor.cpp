#include<bits/stdc++.h>
using namespace std;
int main (){
	int a,b;
	cin>>a>>b;
	if(a==0||b==0){
		cout<<0;
	}else if(b==0||a>0){
		int c=a/2+1;
		cout<<c;
	}else if(a==0||b>0){
		int c=b/2+1;
		cout<<c;
	}else{
		cout<<2;
	}
	return 0;
}
