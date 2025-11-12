#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a+b+c>2*a&&a+b+c>2*b&&a+b+c>2*c){
		cout<<1;
	}
	else{
		cout<<0;
	}
return 0;
} 
