#include<bits/stdc++.h>
using namespace std;
int a[210];
int c[20][20];
int main (){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i = 1;i<=n*m;i++){
		cin>>a[i];
}
int ret = a[1];
sort(a+1,a+n*m+1);
int tot = n*m;
for(int i = 1;i<=m;i++){
	int j;
	if(i%2==1)
	for(int j=1;j<=n;j++){
		c[j][i]=a[tot];
		tot--;	
	}
	else 
	{
	for(int j=m;j>=1;j--){
		c[j][i]=a[tot];
		tot--;	
	}	
	}
	
}
for(int i = 1;i<=n;i++){
	for(int j = 1;j<=m;j++){
		if(c[i][j]==ret){
			
			cout<<j<<" "<<i;
			return 0;
		}
	}
}

return 0;
}

