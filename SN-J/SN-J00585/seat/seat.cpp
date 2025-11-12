#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[105],c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=1,cnt,con=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	cnt=b[1];
	sort(b,b+((n*m)+1));
for(int i=n*m;i>=1;i--){
		c[con]=b[i];
		con++;
	}
   for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				a[i][j]=c[sum];
				sum++;
			}
		}else{
			for(int i=1;i<=n;i++){
				a[i][j]=c[sum];
					sum++;
				}
		  }
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
						if(a[i][j]==cnt){
							cout<<j<<" "<<i;
							return 0;
						}
				}
		}
	return 0;
}
