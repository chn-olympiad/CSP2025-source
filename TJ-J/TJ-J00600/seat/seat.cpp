#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i= 0; i<=m*n-1;i++){
		cin>>a[i];
	}
	int p=a[0];
	for(int j= 0; j<=n*m-1;j++){
		for(int i=0;i<=n*m-2;i++){
			if (a[i]<a[i+1]){
				int e=a[i+1];
				a[i+1]=a[i];
				a[i]=e;
			}
		}
	}
	if(n==1)
	{
		if(m==1){
			cout<<1<<1;
			return 0; 
		}
	}
	if(n==1){
		for(int i= 0; i<=m-1;i++){
			if(a[i]==p)
			{
				cout<<1<<" "<<i+1;
				return 0;
			}
		}
	}
	if(m==1){
		for(int i= 0; i<=n-1;i++){
			if(a[i]==p)
			{
				cout<<i+1<<" "<<1;
				return 0;
			}
		}
	}
	int d[15][15];
	int x=1,y;
	int sum=0;
	while(y!=n&&x!=m){
		for(int y= 0; y<=n-1;y++){
			d[y][x]=a[sum];
			sum++;
		}
		x++;
		sum++;
		for(int y= n-1; y>=0;y--){
			d[y][x]=a[sum];
			sum++;
		}
		x++;
		sum++;
	}
	for(int i= 0; i<=n-1;i++){
		for(int j= 0; j<=m-1;j++){
			if(d[i][j]==p)
			{
				cout<<i<<j;
				return 0;
			}
		}
	}
	return 0;
}
