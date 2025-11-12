#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,a,d,f;
	cin>>m>>a>>d>>f;
	if(a+d>f&&d+f>a&&f+a>d){
		cout<<1;
	}else{
		cout<<0;
	}
} 
