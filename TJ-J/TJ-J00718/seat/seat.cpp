#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[15][15],b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
 	scanf("%d%d%d",&n,&m,&x);b[1]=x;
 	for(int i=2;i<=n*m;i++) scanf("%d",&b[i]);
 	sort(b+1,b+n*m+1,cmp);
 	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==0) for(int i=n;i>=1;i--) a[i][j]=b[++cnt];
		else for(int i=1;i<=n;i++) a[i][j]=b[++cnt];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x) printf("%d %d",j,i);
		}
	}
	return 0;
	
}
