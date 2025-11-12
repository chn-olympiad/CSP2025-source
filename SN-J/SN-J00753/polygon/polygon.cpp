#include<bits/stdc++.h>
using namespace std;
int a,b,c,s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b>>c;
	s=max(a,s);
	s=max(b,s);
	s=max(c,s);
	if(a+b+c>2*s){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
}
