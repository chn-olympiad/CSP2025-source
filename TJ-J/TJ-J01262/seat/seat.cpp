#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=0;
	cin>>n>>m;
	int a[n*m+1]={0},b[n][m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(x%2==0){
			if(y!=1){
				y--;
			}
			else{
				x++;
			}
		}
		else{
			if(y!=n){
				y++;
			}
			else{
				x++;
			}
		}
		if(a[i]==p)
			cout<<x<<' '<<y;
	}
	return 0;
} 
