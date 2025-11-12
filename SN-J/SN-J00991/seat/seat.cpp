#include<bits/stdc++.h>
using namespace std;
int n,m,cmp;
int a[105];
int main(){
	freopen("seat.in","r");
	freopen("seat.out","w");
	cin>>n>>m;
	
	for(int i=0;i<=n*m;i++){
		cout<<a[i];
	}
	if(n==1 && m==1){
		cout<<1<<" "<<1;
	}else if(n<=2 && m<=2){
		cmp=n*m-i+1;
		cout<<cmp/n<<" "<<cmp/m;
	}else if(n<=2 && m<=10){
		cout<<n*m-i+1;
		cout<<cmp/n<<" "<<cmp/m;
	} 
	fclose("saet.in");
	fclose("saet.out");
	return 0;
}
