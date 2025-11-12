#include<bits/stdc++.h>
using namespace std;
int a[101][101],n,m;
struct N{
	int g;
	bool f;
}x[1001];
bool cmp(N a,N b){
	return a.g>b.g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>x[i].g;
		if(i==1)x[i].f=true;
	}
	sort(x+1,x+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				a[i][j]=x[cnt].g;
				if(x[cnt].f==1){
					printf("%d %d",i,j);
					return 0;
				}	
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				a[i][j]=x[cnt].g;
				if(x[cnt].f==1){
					printf("%d %d",i,j);
					return 0;
				}	
			}
		}
	}
	return 0;
}

