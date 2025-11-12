#include<bits/stdc++.h>
using namespace std;
long long n,a[9],k,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>a[i];
		k=max(k,a[i]); 
		m+=a[i];
	}
	if(m*2<k){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
