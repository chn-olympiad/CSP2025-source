#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,po=3,c=0,ans=0,fan=0;
	cin>>n;
	int a[n+3];
	memset(a,0,n+3);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(po<=n){
		for(int i=0;i<n;i++){
			for(int j=i;j<po+i;j++){
				c+=a[j];
				ans=max(ans,a[j]);
			}ans*=2;
			if(c>ans)fan++;
			c=0;
			ans=0;
		}po++;
	}cout<<fan%998244353-1;
	return 0;
} 
