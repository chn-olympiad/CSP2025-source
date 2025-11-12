//SN-J01053  TongChuanShiTaoYuanDiErZhongXiaoXue  HaoTianZhe
#include <bits/stdc++.h>
using namespace std;
struct node{
	int s,p;
}a[10001];
bool cmp(node x,node y){
	return (x.s>y.s);
}
int n,m,c,r;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].s);
		a[i].p=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].p==1){
			c=ceil(1.0*i/n);
			if(c%2){
				r=i-(c-1)*n;
			}else{
				r=abs(i-c*n)+1;
			}
			printf("%d %d\n",c,r);
			break;
		}
	}
	return 0;
}
