#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[110];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int totle=n*m;
	for(int i=1;i<=totle;i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+totle+1,cmp);
	int l=1,r=totle;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]<=k)r=mid;
		if(a[mid]>k)l=mid+1;
	}
	int id=l;
	int lie=id/n+(id%n==0?0:1);
	int hang;
	if(lie%2==1){
		hang=(id%n==0?n:id%n);
	}
	else{
		hang=(n-id%n+1)%n;
		hang=(hang==0?n:hang);
	}
    printf("%d %d",lie,hang);
	return 0;
}
