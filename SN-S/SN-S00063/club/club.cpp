#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int a1[100010];
int b1[100010];
int c1[100010];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			sum+=a[i]+b[i]+c[i];
			int a1[i]=b[i]+c[i];
			int b1[i]=a[i]+c[i];
			int c1[i]=a[i]+b[i];
		}
		int c1=0,c2=0,c3=0;
		int max1=-1,max2=-1,max3=-1;
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]]&&a[i]>c[i]){
				if(c1>=n/2){
					if(a[i])
				}
			}else if(b[i]>a[i]]&&b[i]>c[i]){
				
			}else if(c[i]>a[i]]&&c[i]>b[i]){
				
			}
		}
	}
	return 0;
}
