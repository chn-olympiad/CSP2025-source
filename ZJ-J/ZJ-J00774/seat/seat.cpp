#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int TNT=110;
struct stu{
	int vl,t;
}a[TNT];
int n,m;
bool cmp(stu x,stu y){
	return x.vl>y.vl;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].vl);
	}
	int xr=a[1].vl;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].vl==xr){
			a[i].t=i;
			int lie;
			if(a[i].t%n==0) lie=a[i].t/n;
			else lie=a[i].t/n+1;
			a[i].t%=n;
			if(a[i].t==0) a[i].t=n;
			int hang;
			if(lie%2==1) hang=a[i].t;
			else hang=n-a[i].t+1;
			printf("%d %d",lie,hang);
			break;
		}
	}
	return 0;
}
