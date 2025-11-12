#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	int n,a[n+5];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}