#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0,m=0;
	for(int i=1;i<=n;i++){
		m+=a[i];
		if(i>=3&&m>a[n]*2){
			num++;
		}
	}
	cout<<num%998%244%353;
	return 0;
}


