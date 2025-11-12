#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[108];
int b[18][18];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	int score=a[1];
	for(int i=2;i<=n*m;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(j%2){
				if(a[i+(j-1)*n]==score) printf("%d %d",j,i);
			}else{
				if(a[(n-i+1)+(j-1)*n]==score) printf("%d %d",j,i);
			}
		}
	}
	return 0;
}
