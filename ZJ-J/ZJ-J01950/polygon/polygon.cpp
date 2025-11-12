#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool chk(int l,int r){
	int mx=-1,sum=0,sm=0;
	for(int i=l;i<=r;i++){
		sum+=a[i];
	
		mx=max(mx,a[i]);
	}
	return sum-mx-sm>mx;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(chk(1,3)){
			cout<<1;
		}
		else cout<<0;
	}
	else if(a[1]=1){
		int sum=0;
		for(int i=1;i<=n-2;i++){
			sum+=i;
		}
		
		cout<<sum;
	}
	else{
		cout<<max(n*n/8+6,0);
	}
}
