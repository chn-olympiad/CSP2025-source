#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	int z=a+b+c;
	int d=max(a,b,c)*2;
	if(z>d){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
