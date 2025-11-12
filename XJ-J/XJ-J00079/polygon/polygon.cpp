#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a,b,c,maxn;
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	cin>>a>>b>>c;
	maxn=max(a,b);
	maxn=max(maxn,c);
	if(a+b+c>maxn*2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0; 
}




