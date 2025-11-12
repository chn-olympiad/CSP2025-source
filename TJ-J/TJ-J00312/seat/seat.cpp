#include<bits/stdc++.h>
using namespace std;
int n,m;
struct zw{
	int cj,sx;
	int bj=0;
	int h=1,l=1;
}a[105];
int cmp(zw x,zw y){
    return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
	}
	a[1].bj=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].sx=i;
	}
	for(int i=1;i<=n*m;i++){
		while(a[i].sx>n){
			a[i].sx-=n;
			a[i].l++;
		}
		if(a[i].l%2==1){
			a[i].h=a[i].sx;
		}else{
			a[i].h=n-a[i].sx+1;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].bj==1){
			cout<<a[i].l<<" "<<a[i].h<<endl;
		}
	}
	return 0;
} 
