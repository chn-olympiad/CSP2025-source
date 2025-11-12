#include<iostream>
using namespace std;
int a[5001],pf=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			pf=0;
	}
	if(pf)
		cout<<n-2;
	return 0;
}
