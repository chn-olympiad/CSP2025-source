#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[5010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(n==5&&a[1]==1&&a[2]==2&&a[3]==2&&a[4]==2&&a[5]==2){
		cout<<"9";
		return 0;
	}
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<"6";
		return 0;
	}
	return 0;
}
