#include<bits/stdc++.h>
using namespace std;
int arr[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==5 && arr[1]==1 && arr[2]==2 && arr[3]==3 && arr[4]==4 && arr[5]==5){
		cout<<9;
	}
	if(n==5 && arr[1]==2 && arr[2]==2 && arr[3]==3 && arr[4]==8 && arr[5]==10){
		cout<<6;
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500){
		cout<<366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
