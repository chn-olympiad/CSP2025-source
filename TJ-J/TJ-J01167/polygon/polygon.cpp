#include<bits/stdc++.h>
using namespace std;
 
int a[100005];
int qian[100005];
int n;
int ans;
int ans1;
int shuliang;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==4){
		if(a[1]+a[2]>a[3]){
			ans++;
		}
		if(a[1]+a[2]>a[4]){
			ans++;
		}
		if(a[2]+a[3]>a[4]){
			ans++;
		}
		if(a[1]+a[2]+a[3]>a[4]){
			ans++;
		}
		cout<<ans;		
	}else if(n==5){
		if(a[1]+a[2]>a[3]){
			ans++;
		}		
		if(a[1]+a[2]>a[4]){
			ans++;
		}
		if(a[1]+a[2]>a[5]){
			ans++;
		}
		if(a[1]+a[3]>a[4]){
			ans++;
		}
		if(a[1]+a[3]>a[5]){
			ans++;
		}
		if(a[1]+a[4]>a[5]){
			ans++;
		}	
		if(a[2]+a[3]>a[4]){
			ans++;
		}		
		if(a[2]+a[3]>a[5]){
			ans++;
		}		
		if(a[2]+a[4]>a[5]){
			ans++;
		}
		if(a[3]+a[4]>a[5]){
			ans++;
		}
		if(a[1]+a[2]+a[3]>a[4]){
			ans++;
		}
		if(a[1]+a[2]+a[3]>a[5]){
			ans++;
		}
		if(a[1]+a[2]+a[4]>a[5]){
			ans++;
		}
		if(a[1]+a[3]+a[4]>a[5]){
			ans++;
		}
		if(a[2]+a[3]+a[4]>a[5]){
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[5]){
			ans++;
		}
		cout<<ans;		
	}else{
		for(int j=3;j<=n;j++){
			ans1=1;
			for(int i=1;i<=j;i++){
				ans1*=(n-i+1);
			}
			for(int i=1;i<=j;i++){
				ans1/=i;
			}
			ans+=ans1;
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
