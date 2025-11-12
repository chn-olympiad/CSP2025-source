#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,an=0;
	int a[110]={},b[20][20]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i=i+1){
		cin>>a[i];
		if(i==0){
			R=a[i];
		}
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<m;i=i+1){
		if(i%2==0){
			for(int j=0;j<n;j=j+1){
				b[j][i]=a[an];
				an=an+1;
			}
		}
		else{
			for(int j=n-1;j>=0;j=j-1){
				b[j][i]=a[an];
				an=an+1;
			}
		}
	}
	for(int i=0;i<n;i=i+1){
		for(int j=0;j<m;j=j+1){
			if(b[i][j]==R){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
