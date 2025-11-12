//SN-J01215 齐睿渊  富平县怀德初级中学 
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[0]+a[1]+a[2]>2*a[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
