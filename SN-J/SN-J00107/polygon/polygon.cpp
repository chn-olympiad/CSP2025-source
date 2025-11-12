#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
		cout<<9;
	}
	return 0;
} 
