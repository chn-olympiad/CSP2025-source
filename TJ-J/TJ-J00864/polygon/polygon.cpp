#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	int n;
	int mx[5005]={-1}; 
	int a[5005];
	int ans[5005]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		 if(a[i]>mx[n]){
		 	mx[i+n]==a[++i];
		 	mx[i+1]=a[i-(n+1)];
		 	ans[i]=mx[i+n]+mx[i+1];
		 }
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i+1+n];
	}
	return 0; 
}
