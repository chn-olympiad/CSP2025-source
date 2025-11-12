#include<bits/stdc++.h>
using namespace std;
int a[110],b[110],c[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int d=a[1],e=n*m,f=m*n,i=1,j=1;
	sort(b+1,b+n*m+1);
	while(f--){
		c[i][j]=b[f+1];
		if(c[i][j]==d){
			cout<<j<<' '<<i;
			return 0;
		}
		if(i<n&&j%2!=0)i++;
		else if(j%2==0&&i>1)i--;
		else if(i==n||i==1)j++;
	}
	return 0;
}
