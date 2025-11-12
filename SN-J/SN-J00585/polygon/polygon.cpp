#include<bits/stdc++.h>
using namespace std;
	int n,cnt,sum=-10000000;
	int a[1005],b[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}	
	sort(a,a+(n+1));
	for(int i=1;i<=n+1;i++){
		    b[i]=b[i-1]+a[i];	
	}
     for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(a[k]>sum){
					sum=a[k];
				}
				
			}
			if(b[j]-b[i-1]>sum*2){
					cnt++;
			}
			sum=-1000000000;
		} 
	}
	cout<<cnt;
	return 0;
}
