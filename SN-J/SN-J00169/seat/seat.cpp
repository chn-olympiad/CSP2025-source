//原梓轩 SN-J00169 440514201308033019 陕西-西安-锦园中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int sum;
bool cmp(int a,int b){
	return a>b;
}
int  main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	sum=a[0];
	sort(a,a+n*m);
	int ans;
	for(int i=0;i<n*m;i++){
		if(a[i]==sum){
			ans=i;
		}
	}
	cout<<ans%m+1<<" ";
	if(ans%m%2==0){
		cout<<m-ans%n;
	}
	else{
		cout<<ans%n;
	}
	return 0;
}
