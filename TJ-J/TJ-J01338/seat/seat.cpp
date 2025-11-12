#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	int n,m,a[101],q,b[101][101],sum=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=n*m;
	q=a[1];
	sort(a+1,a+n*m+1);

	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[sum];
				sum--;
			}
		}
		else{
			for(int j=n;j>=1;j--){

				b[i][j]=a[sum];
				sum--;
			}
		}
	}
	for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
		if(b[i][j]==q){
			cout<<i<<" "<<j;
			return 0;
		}
				
				
		}
	}
	fclose(stdin);
fclose(stdout);
	return 0;
}
