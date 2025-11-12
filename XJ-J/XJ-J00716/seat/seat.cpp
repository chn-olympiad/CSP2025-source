#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0,idx,idy,f;
	cin>>n>>m;
	int b[n][m];
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	f=a[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=i+1;j<n*m;j++){
			if (a[i]<a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			} 
		}
	}
	for(int i=0;i<m;i++){
		if (i%2==0){
			for(int j=0;j<n;j++){
				b[i][j]=a[k];
				if (a[k]==f){
					idx=i;
					idy=j;
				}
				k++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				b[i][j]=a[k];
				if (a[k]==f){
					idx=i;
					idy=j;
				}
				k++;
			}
		}
	}
	cout<<idx+1<<" "<<idy+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
