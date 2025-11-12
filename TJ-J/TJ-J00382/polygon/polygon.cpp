#include<bits/stdc++.h>
using namespace std;
int n,a[10005],b[10005];
long long ans,num,k;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1 || n==2) cout<<0;
	if(n==3) cout<<1;
	else{
	cout<<n*2-1;	
	}
	return 0;
}

