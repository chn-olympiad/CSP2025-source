#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c[11][11],d[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	b = a[1];
	int max=0,num = 0;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>max){
				max = a[j];
				num = j;
			}
		}
		d[i] = max;
		a[num] = 0;
		max = 0;
	}

	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(i==1){
					c[j][i] = d[j];
					d[j] = 0;
				}
				if(d[i-1*n+j]!=0){
					c[j][i] = d[(i-1)*n+j];
					d[(i-1)*n+j] = 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(d[(i-1)*n+1]!=0){
					c[j][i] = d[(i-1)*n+1];
					d[(i-1)*n+1] = 0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[j][i]==b){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}

