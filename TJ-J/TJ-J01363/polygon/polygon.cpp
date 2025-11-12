#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>a[k]*2){
					m++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++){
					if(a[i]+a[j]+a[k]+a[l]>a[l]*2){
						m++;
					}
				}
			}
		}
	}
	if(a[0]+a[1]+a[2]+a[3]+a[4]>a[4]*2){
		m++;
	}
	cout<<m;
	return 0;
} 
