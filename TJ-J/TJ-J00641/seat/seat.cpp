#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int b[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;  
	int sum=n*m;
	//cout<<sum<<endl;
	for(int i=1;i<=sum;i++){
	cin>>b[i];
//	cout<<b[i];
}
	int l=b[1];
	sort(b,b+sum+1);
	for(int i=1;i<=sum;i++){
	//	cout<<b[i];
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
		for(int j=1;j<=n;j++){
			a[j][i]=b[sum];
			sum--;
		}	
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[sum];
					sum--;
			
			}
		}
}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==l){
					cout<<j<<" "<<i;
				}
	//	cout<<a[i][j];
			}
	//		cout<<endl;
		}
		return 0;
		
}
