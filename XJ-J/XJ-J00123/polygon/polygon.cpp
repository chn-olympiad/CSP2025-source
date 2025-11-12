#include<bits/stdc++.h>
using namespace std;
int num[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		num[i]=a;
	}
	if(n>=3){
	int ma=0;	
		for (int i=1;i<=n;i++){
		if(num[i]>ma){
			ma=num[i];
		}
	}
		if(num[1]+num[2]+num[3]>2*ma){
			cout<<1;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
