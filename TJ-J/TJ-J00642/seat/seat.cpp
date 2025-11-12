#include<bits/stdc++.h>
using namespace std;
struct num{
	int cj;
	int x;
	int y;
	int xh;
}b[110]={};
int n,m;
int bj=0;
int a[110];
int k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	bj=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		b[k].cj=a[i];
		b[k].xh=k;
		k++;
	}
	int jj=1;
	for(int i=1;i<=n;i++){
		b[i].x=1;
		b[i].y=jj;
		jj++;
	}
	int nn=n;
	for(int i=n+1;i<=2*n;i++){
		b[i].x=2;
		b[i].y=nn;
		nn--;
	}
	jj=1;
	for(int i=2*n+1;i<=3*n;i++){
		b[i].x=3;
		b[i].y=jj;
		jj++;
	}
	nn=n;
	for(int i=3*n+1;i<=4*n;i++){
		b[i].x=4;
		b[i].y=nn;
		nn--;
	}
	jj=1;
	for(int i=4*n+1;i<=5*n;i++){
		b[i].x=5;
		b[i].y=jj;
		jj++;
	}
	nn=n;
	for(int i=5*n+1;i<=6*n;i++){
		b[i].x=6;
		b[i].y=nn;
		nn--;
	}
	jj=1;
	for(int i=6*n+1;i<=7*n;i++){
		b[i].x=7;
		b[i].y=jj;
		jj++;
	}
	nn=n;
	for(int i=7*n+1;i<=8*n;i++){
		b[i].x=8;
		b[i].y=nn;
		nn--;
	}
	jj=1;
	for(int i=8*n+1;i<=9*n;i++){
		b[i].x=9;
		b[i].y=jj;
		jj++;
	}
	nn=n;
	for(int i=9*n+1;i<=10*n;i++){
		b[i].x=10;
		b[i].y=nn;
		nn--;
	}
	for(int i=1;i<=n*m;i++){
		if(b[i].cj==bj){
			cout<<b[i].x<<" "<<b[i].y<<endl;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
