#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("polygon","r",in);
//	freopen("polygon","w",out);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
	} 
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c<max(a,max(b,c))*2){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
//	freclose("polygon",in);
//	freclose("polygon",out);s
	return 0;
}
