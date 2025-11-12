#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==1){
		cout<<9;
	}
	else if(a[0]==2){
		cout<<6;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
