#include<iostream>
#include<cmath>
int n,a[5000],ans=0;
using namespace std;
void f3(int x){
	for(int i=x;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if((a[i]+a[j]+a[k])>2*max(a[i],max(a[j],a[k]))){
					ans++;
				}
			}
		}
	}
}
void f4(int x){
	for(int b=x;b<=n-3;b++){
		for(int i=b+1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if((a[b]+a[i]+a[j]+a[k])>2*max(a[b],max(a[i],max(a[j],a[k])))){
						ans++;
						cout<<a[b]<<a[i]<<a[j]<<a[k]<<endl;
					}
				}
			}
		}
	}
} 
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]; 
	f3(0);
	f4(0);
	cout<<ans; 
	return 0;
}
