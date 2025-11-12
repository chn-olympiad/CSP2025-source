#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool flag1=0,flag2=0,flag3=0;
	int a[5006];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>=a[3] && a[2]+a[3]>=a[1]&&a[1]+a[3]>=a[2]){
			if(a[1]>=a[2]){
				if(a[1]-a[2]<=a[3]){
					flag1=1;
				}
			}else if(a[1]<=a[2]){
				if(a[2]-a[1]<=a[3]){
					flag1=1;
				}
			}else if(a[3]<=a[2]){
				if(a[2]-a[3]<=a[1]){
					flag2=1;
				}
			}else if(a[3]>=a[2]){
				if(a[3]-a[2]<=a[1]){
					flag2=1;
				}
			}else if(a[3]>=a[1]){
				if(a[3]-a[1]<=a[2]){
					flag3=1;
				}
			}else if(a[3]<=a[1]){
				if(a[1]-a[3]<=a[2]){
					flag3=1;
				}
			}
		}
	}
	if(flag1==flag2==flag3==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
