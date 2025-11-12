#include<bits/stdc++.h>
using namespace std;
int a[50000];
int seatt[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//cout<<int('0');//48
	//cout<<int('9');//57
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int jsq=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				
				seatt[i][j]=a[jsq];
				jsq++;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				seatt[i][j]=a[jsq];
				jsq++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seatt[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
} 
