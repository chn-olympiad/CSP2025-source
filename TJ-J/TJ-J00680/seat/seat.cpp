#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],t,cj;
bool cmp(int,int);
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[++t]);
		}
	}
	cj=a[1];
	sort(a+1,a+t+1,cmp);
	t=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[++t]==cj){
				printf("%d %d",i,j);
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			if(a[++t]==cj){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
bool cmp(int a,int b) {
	return a>b;
}

