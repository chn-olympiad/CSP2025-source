#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,a[100],a1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int j=0;j<a1;j++){
		if(a[i]>a[j]){
			cout<<"1 1";
		}
		if(a[i]<a[j]){
			cout<<"1 2";
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
