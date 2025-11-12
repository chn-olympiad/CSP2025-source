#include<iostream>
using namespace std;
int x[100][100];
int main(){
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]={};
	int max=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	int r;
	int c[n*m]={};
	int b[n*m]={};
	for(int i=0;i<n*m;i++){
		int max1;
		max=0;
		for(int j=0;j<n*m;j++){
			b[j]=a[j];
			if(b[j]>=max){
				max=b[j];
				max1=j;
			}
		}
		c[i]=max;
		if(c[i]==y){
			r=c[i];
		}
		a[max1]=-1;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				x[n][m]=c[i*m];
				if(x[n][m]==y){
					cout<<m<<" "<<n;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				x[n][m]=c[i*m];
				if(x[n][m]==y){
					cout<<m<<" "<<n;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

