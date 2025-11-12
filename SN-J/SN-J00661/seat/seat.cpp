//SN-J00661 樊仕博 华阴市城关初级中学
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100001];
int b[10001][10001];
int h,l;
int r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	int num=n*m;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[num];
				num--;
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[num];
				num--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==b[i][j]){
				h=i;
				l=j;
			}
		}
	}
	printf("%d %d",l,h);
	return 0;
}
