#include<bits/stdc++.h>
using namespace std;
int n,a[5],max1=INT_MIN,s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>max1){
			max1=a[i];
		}
		s=s+a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3&&s>2*max1){
		cout<<"1";
		return 0;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
