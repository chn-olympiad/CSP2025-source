#include<iostream>
using namespace std;
int a[100001],n,k;
bool pf1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			pf1=0;
	}
	if(pf1&&!k)
		cout<<n/2;
	return 0;
} 
