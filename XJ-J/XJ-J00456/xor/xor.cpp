#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			x++;
		}else{
			y++;
		}
	} 
	if(k==0 && x==n){
		if(n%2==0){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}else if(k==1){
		if(y%2==0){
			cout<<y;
		}else{
			cout<<1;
		}
	}else{
		cout<<1;
	}
	
	return 0;
} 
