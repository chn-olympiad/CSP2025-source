#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ma=0,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			if(a[i]>=ma){
				ma=a[i];
			}
	}
	if(n=3){
		if(sum>ma*2){
			cout<<"1";
		}
	}
	return 0;
} 
