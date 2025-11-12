//周琪明 SN-J00213 西安滨河学校
#include<bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
int n,a[5000],zh_m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>a[0]*2&&a[0]+a[1]+a[2]>a[1]*2&&a[0]+a[1]+a[2]>a[2]*2){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else{
		zh_m=(n-1)*n/2;
		printf("%d",n%998%244*353);
	}
	return 0;
}
