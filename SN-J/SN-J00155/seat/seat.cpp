#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,b[101]={0},R,h,a[11][11]={};
	cin>>n>>m>>b[1];
	R=b[1];
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(b[i]<b[j]){
				h=b[i];
				b[i]=b[j];
				b[j]=h;
			}
		}
	}
	int k=1,x=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			while(k<=n){
				a[k][j]=b[x];
				if(a[k][j]==R){
					c=j,r=k;
					//break;
				}
				k++;
				if(k>n){
					break;
				}
				x++;
			}
		}
		else{
			while(k>=1){
				a[k][j]=b[x];
				if(a[k][j]==R){
					c=j,r=k;
					//break;
				}
				k--;
				if(k<1){
					break;
				}
				x++;
			}
		}
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
