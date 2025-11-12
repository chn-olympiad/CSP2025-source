#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][3],d[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				
			}
		}
	}
	for(int i=1;i<=t;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(a[j-1][k]>a[j][k]){
				    if(d[j]<=n/2){
				        a[j][k]=a[j-1][k];
				        cnt+=a[j][k];
				        d[j]++;    
				}   }     
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 



