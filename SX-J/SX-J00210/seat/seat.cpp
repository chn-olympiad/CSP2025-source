#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,huan,zuo[n*m],da,h;
	cin>>n>>m;
	int x[m][n];
	int f[m*n];
	for(int i=0;i<m*n;i++){
		cin>>f[i];
	}
	da=f[0];
	for(int i=0;i<n*m;i++){
		for(int t=0;t<n*m;t++)
		if(f[t]<f[t+1]){
		huan=f[t];
		f[t]=f[t+1];
		f[t+1]=huan;
		}
	}
	for(int i=0;i<n*m;i++){
		for(h=0;h<n;h++){
			zuo[n][m]=f[i];
		}
		m++;
	}
	bool u=0;
	for(int i=0;i<n*m;i++){
		for(h=0;h<=n;h++){
			if(zuo[h][m]==da&&u==0){
				cout<<[n][m];
				u=1;
				break;

			}

		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}