#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,v;
};
node a[100006];
int b[105][105];
inline bool cmp(node a,node b){
	return a.v>b.v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			p=i;
			break;
		}
	}
	int x=-1,y=-1;
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=++cnt;
				if(b[i][j]==p){
					x=i;
					y=j;
					break;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=++cnt;
				if(b[i][j]==p){
					x=i;
					y=j;
					break;
				}
			}
		}
		if(x!=-1&&y!=-1){
			break;
		}
	}
	printf("%d %d",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

