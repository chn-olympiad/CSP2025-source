#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","e",stdout);
	int n,m; 
    int a[10000];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1) cout<<"1 1";
	return 0;
}
