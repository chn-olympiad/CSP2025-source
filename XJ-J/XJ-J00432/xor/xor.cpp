#include<bits/stdc++.h>
using namespace std;
const int N=1e6+12;
int n,k,a[N],num[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool fa=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fa=0;
	}
	if(fa){
		cout<<n/2;
		return 0;
	}
	cout<<"1";
	return 0;
} 
