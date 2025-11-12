#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygom.in","r",stdin);
	freopen("polygom.out","w",stdout);
	int n,a[6];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
    return 0;
} 
