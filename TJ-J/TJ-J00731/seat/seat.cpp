#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[123],x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int d=b[1];
	for(int j=0;j<n*m;j++){
		int max=b[0],t=0,c,e=x;
		for(int i=1;i<n*m;i++){
			if(b[i]>=max&&b[i]!=-1){
				max=b[i];
				t=i;
			}
		}
		a[x][y]=max;
		b[t]=-1;
		c=b[t];
		b[t]=b[n-j];
		b[n-j]=c;
		if(y<m&&x==1) y++;
		if(y==m||y==1){
			x++;
		}
		if(x=e+1&&y==m){
			y--;	
		}
		if(x!=1&&y==1){
			x++;
		}
		if(x=e+1&&y==1){
			y++;
		}
		if(a[x][y]=d) break;
	}
	cout<<x<<" "<<y;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
