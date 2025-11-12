#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1,k=0;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				k++;
				b[i][j]=a[k];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				k++;
				b[i][j]=a[k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
