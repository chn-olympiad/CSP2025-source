#include<bits/stdc++.h> 
using namespace std;
long long n,m,c,s,i,j,k,p,q;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
