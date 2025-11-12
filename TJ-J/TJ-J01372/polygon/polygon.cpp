#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>e>>a>>b>>c;
	d=a+b+c;
	e=max(a,max(b,c));
	if(d>e*2){
		cout<<1;
		return 0;
	}
	cout<<2;
	return 0;
} 
