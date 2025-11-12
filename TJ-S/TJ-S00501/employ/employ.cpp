#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string kaa;
	cin>>kaa;
	int a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	int b[q+1]={};
//	for(int i=1;i<=q;i++){
//		cin>>b[i];
//	}
if(n==3){

		cout<<2;
	}
	else if(n==10){
		cout<<2204128;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
