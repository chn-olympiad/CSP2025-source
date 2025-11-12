#include<bits/stdc++.h>

using namespace std;
int x,n,a[10001][10001],sum1=0,sum2=0,sum3=0;
int n1[10001],n2[10001],n3[10001];
int main(){
	freopen("club .in","r",stdin);
	freopen("club .in","w",stdout);
	cin>>x;
	while(x--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(j==0){
					n1[i]=a[i][j];
				}else if(j==1){
					n2[i]=a[i][j];
				}else{
					n3[i]=a[i][j];
				}
			}
		}
				
	}
	return 0;
} 
