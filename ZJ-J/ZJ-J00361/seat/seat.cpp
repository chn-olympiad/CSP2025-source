#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,b[1005][1005];
struct Info{
	int x,id;
	bool operator < (const Info A)const{
		return A.x<x;
	}
}a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	int num=1,x=1,y=1;
	while(num<=n*m){
		while(1){
			if(x==n+1){
				x=n;
				break;
			}
			b[x][y]=num;num++;
			x++;
		}
		y++;
		while(1){
			if(x==0){
				x=1;
				break;
			}
			b[x][y]=num;num++;
			x--;
		}
		y++;
	}
	int id=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			id=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==id){
				printf("%d %d\n",j,i);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}