#include<bits/stdc++.h>
using namespace std;
int n;
int num=0;
int cnt=0;
struct f{
	int x;
	int y;
	int z;
	int fl;
}a[100005];
int cmp1(f x,f y){
	return x.x>y.x;
}
int cmp2(f x,f y){
	return x.y>y.y;
}
void work(){
	scanf("%d",&n);
	cnt=0;
	for(int i=1;i<=n;i++){
		a[i].fl=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+n+1,cmp1);
	num=0;
	for(int i=1;i<=n;i++){
		if(num==n/2){
			break;
		}
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
			cnt+=a[i].x;
			num++;
			a[i].fl=1;
		}
	}
	sort(a+1,a+n+1,cmp2);
	num=0;
	for(int i=1;i<=n;i++){
		if(num==n/2){
			break;
		}
		if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&a[i].fl==0){
			cnt+=a[i].y;
			num++;
			a[i].fl=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!a[i].fl){
			cnt+=a[i].z;
		}
	}
	printf("%d\n",cnt);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		work();
	}
	
	return 0;
}
