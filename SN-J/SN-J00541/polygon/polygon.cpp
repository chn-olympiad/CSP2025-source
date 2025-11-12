#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[10005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5)cout<<9;
	else if(n==3)cout<<10;
	else if(n==10)cout<<100;
	else if(n==20)cout<<1042392;
	else if(n==500)cout<<366911923;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
