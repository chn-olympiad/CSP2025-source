#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long x[15][15],n,m,a,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
    		cin>>x[i][j];
    		if(i==0&&j==0) a=x[i][j];
			if(x[i][j]>a) sum++;	
		}
	}
	for(int k=n;k<n*m;k+=n){
		if(sum<k){
			for(int i=0;i<m;i++){
				if(i==0||i%2==0){
					cout<<i+1<<' '<<n-k+sum+1;
					return 0;
				}else{
					cout<<i+1<<' '<<k-sum+1;
					return 0;
				}
			}
		}else if(sum==k){
			for(int i=0;i<m;i++){
				if(i==0||i%2==0){
					cout<<i+1<<' '<<n;
					return 0;
				}else{
					cout<<i+1<<' '<<1;
					return 0;
				}
			}
		}
	}
	return 0;
}
