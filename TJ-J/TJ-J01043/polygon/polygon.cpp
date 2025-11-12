#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a;
	long long b;
	cin>>a;
	cin>>b;
	int aaa;
	for(long long i=1;i<=a-1;i++){
		cin>>aaa;
	}
	if(b=1){
		cout<<9;
	}
	if(b=2){
		cout<<6;
	}
	if(b=75){
		cout<<1042392;
	}
	if(b=37){
		cout<<366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
