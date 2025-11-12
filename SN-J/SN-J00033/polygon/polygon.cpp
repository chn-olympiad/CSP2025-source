#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10005],b[10005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1]+a[i];
	}
	if(b[n]-a[n]<=a[n]){
		cout<<0;
	}else{
		cout<<1;
	}
		 
	
	//for(int i=1;i<=n;i++){
	//	cout<<b[i]<<" "<<a[i]<<" ";
	//}
	return 0;
}
