#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int a[105],b[12][12];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];	
		if(i==1){
			x=a[1];
		}
	}
	sort(a+1,a+1+(m*n));
	for(int i=1;i<=n*m/2;i++){
		int c=a[i];
		a[i]=a[m*n-i+1];
		a[m*n-i+1]=c;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				b[j][i]=a[n*(i-1)+j];
				if(x==a[n*(i-1)+j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}else{
				b[j][i]=a[n*i-j+1];				
				if(x==a[n*i-j+1]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
