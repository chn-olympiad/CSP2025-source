#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std; 
int n,m;
struct node{
	int f,id;
}a[105];
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].f);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=m;j++){
				cnt++;
				if(a[cnt].id==1){
					printf("%d %d",i,j);
					break;
				}
			}
		else
			for(int j=m;j>=1;j--){
				cnt++;
				if(a[cnt].id==1){
					printf("%d %d",i,j);
					break;
				}
			}
	}
	return 0;
}
