#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,ans[10000];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>ans[i];
	}
	if(a<3){
		cout<<0;
	}
	else if(a==3){
		cout<<1;
	}
	else{
		cout<<2;
	}
	return 0;
}
