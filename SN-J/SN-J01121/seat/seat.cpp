#include<bits/stdc++.h>
using namespace std;
int a[105];
int z[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	int n,m,r;
	cin>>n>>m;
	int he=n*m;
	for(int i=1;i<=he;i++){
		cin>>a[i];
		r=a[1];
	}
	for(int i=2;i<=n*m;i++){
		for(int j=1;j<i;j++){
			if(a[j]<=a[i]){
				int bi=a[j];
				a[j]=a[i];
				a[i]=bi;	
			}	
		}
	}
	int t=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(t<=n*m){
					if(j%2!=0){
					z[j][i]=a[t];
					if(a[t]==r){
						cout<<j<<" "<<i;
						return 0;
					}
				}
				else if(j%2==0){
					z[j][n-i+1]=a[t];
					if(a[t]==r){
						cout<<j<<" "<<n-i+1;
						return 0;
					}
				}
			t++;
			}	
		}
	}
}
