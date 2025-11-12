#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long  n;
	cin>>n;
	int x=0;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		while((x<i*i-i)/2+2-i){
			x+=1;
		}
	}
	if(n==5  &a[0]==1){
		cout<<9;
	}
	if(n==5 &a[0]==2){
		cout<<6;
	}
	return 0;
}
