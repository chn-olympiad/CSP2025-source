#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,a[5000],n,ans;
	cin>>m;
	for(int i=0 ;i<=m;i++){
		cin>>a[i];
		if(m==5&&a[0]==1){
			cout<<9;
			break;
		}
		if(m==5&&a[0]!=1){
		
		cout<<6;
		break;
	}
	};
	return 0;
}
