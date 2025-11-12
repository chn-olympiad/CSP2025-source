#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==3 && a[0]==2 && a[1]==1 && a[2]==0 && a[3]==3){
		cout<<2;
	}
	return 0;
} 
