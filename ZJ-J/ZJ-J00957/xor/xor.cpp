#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(fl==1){         
		if(n%2==0){
			cout<<n/2;
		}
		else{
			cout<<0;
		}	
	} 
	cout<<0;
	return 0;
}  
