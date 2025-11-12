#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,val;
int a[102],ans[12][12];
bool flag=true;	//true：从上往下，false：从下往上 
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	val=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1;
	for(int i=1;i<=n*m;i++){
		ans[x][y]=a[i];
		if(x==n&&flag)	y++,flag=false;
		else if(x==1&&!flag)	y++,flag=true;
		else if(flag)	x++;
		else if(!flag)	x--;
//		printf("%d %d\n",x,y);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			printf("%d ",ans[i][j]);
//		printf("\n");
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j]==val){
				printf("%d %d",j,i);
				return 0;
			}
	return 0;
}

