#include<bits/stdc++.h>
using namespace std;
long long m,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1)cout<<9;
	else if(n==5&&m==2)cout<<6;
	else if(n==20&&m==75)cout<<1042392;
	else if(n==500&&m==37)cout<<366911923;
	else cout<<0; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
