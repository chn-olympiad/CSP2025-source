#include<iostream>
using namespace std;
int a[101][101];
int main(){
	int n,m,x,y,t;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int f=1;f<=m;f++)
			cin>>a[i][f];
	}
	y=a[1][1];
	t=a[1][1];
	for(int i=1;i<=n;i++){
		for(int f=1;f<=m;f++)
			if(n<a[i][f]){
				y=x;
				x=a[i][f];
				a[i][f]=y;
			}
	}
	for(int i=n;i>=1;i--)
		for(int f=m;f>=1;f--)
				if(t=a[i][f])
				{
					cout<<i<<" "<<f;
				}
	return 0;		
} 
