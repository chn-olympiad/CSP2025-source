#include<bits/stdc++.h>
using namespace std;
const int inf=1000005;
int n;
int a[inf];
int cnt;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int t=3;
	int l=1,r=3;
	while(t<n){	
	 	if(t==3){
	 		for(int i=1;i<=n-2;i++){
	 			for(int j=2;j<=n-1;j++){
	 				for(int k=3;k<=n;k++){
	 					if(i<j&&j<k&&a[i]+a[j]>a[k]){
	 						cnt++;
						 }
					 }
				 }
			 }
		 }else if(t==4){
		 	for(int i=1;i<=n-3;i++){
	 			for(int j=2;j<=n-2;j++){
	 				for(int k=3;k<=n-1;k++){
	 					for(int h=4;h<=n;h++){
	 						if(a[i]+a[j]+a[k]>a[h]&&i<j&&j<k&&k<h){
	 							cnt++;
						 	}
						 }
	 					
					 }
				 }
			 }
		 }else if(t==5){
		 	for(int i=1;i<=n-4;i++){
	 			for(int j=2;j<=n-3;j++){
	 				for(int k=3;k<=n-2;k++){
	 					for(int h=4;h<=n-1;h++){
	 						for(int q=5;q<=n;q++){
	 							if(i<j&&j<k&&k<h&&h<q&&a[i]+a[j]+a[k]+a[h]>a[q]){
	 								cnt++;
						 		}
							}
	 						
						 }
	 					
					 }
				 }
			 }
		 }
		 t++;
	}
	cout<<cnt+1;
	return 0;	          
}