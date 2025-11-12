#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],f[15][15],x;
int cmp(int t,int tt){
	return t>tt;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,num=a[1],t=1; 
	while(i<=n && j<=n){
		f[i][j]=num;
		if(j%2!=0){
			if(i<n){
				i++;
			}else if(i==n){
				j++;
			}
		}else if(j%2==0){
			if(i>1){
				i--;
			}else if(i==1){
				j++;
			}
		}
		num=a[++t];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==x){
				printf("%d %d",j,i);
			}
		}
	}
	return 0;
}