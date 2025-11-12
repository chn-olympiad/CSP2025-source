#include<bits\stdc++.h>
 using namespace std;
 const int N=1e3+9;
 int main (){
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	int n,a[N];
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	 }
 	if(n<3){
		cout<<0;
	}
	else if(n==3){
		int ma=0,sum=0;
		for(int i=1;i<=3;i++){
			if(a[i]>=ma){
				ma=a[i];
			}
			sum+=a[i];
		}
		if(sum>ma*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n>3&&n<=5){
		int ssum=0;
		for(int k=1;k<=n-2;k++){
			for(int x=2;x<=n-1;x++){
				for(int i=3;i<=n;i++){
					int ma=0,sum=0;
					for(int j=1;j<=n;j++){
						if(j==k || j==x || j==i){
							if(a[j]>ma){
								ma=a[j];
							}
							sum+=a[j];
						}
					}
					if(sum>ma*2){
						ssum+=1;
					}
				}
			}
		}
		for(int c=1;c<=n-3;c++){
			for(int k=2;k<=n-2;k++){
			for(int x=3;x<=n-1;x++){
				for(int i=4;i<=n;i++){
					int ma=0,sum=0;
					for(int j=1;j<=n;j++){
						if(j==c || j==k || j==x || j==i){
							if(a[j]>ma){
								ma=a[j];
							}
							sum+=a[j];
						}
					}
					if(sum>ma*2){
						ssum+=1;
					}
				}
			}
		}	
		}
		for(int g=1;g<=n-4;g++){
			for(int c=2;c<=n-3;c++){
			for(int k=3;k<=n-2;k++){
			for(int x=4;x<=n-1;x++){
				for(int i=5;i<=n;i++){
					int ma=0,sum=0;
					for(int j=1;j<=n;j++){
						if(j==g || j==c || j==k || j==x || j==i){
							if(a[j]>ma){
								ma=a[j];
							}
							sum+=a[j];
						}
					}
					if(sum>ma*2){
						ssum+=1;
					}
				}
			}
		}	
		}
		}
		cout<<ssum;
	}
 	
 	
 	return 0;
 }
