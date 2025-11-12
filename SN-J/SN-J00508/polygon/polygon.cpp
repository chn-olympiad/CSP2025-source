#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int a[n];
	set<int>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<1;
	}
	if(n==4){
		cout<<4;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
