#include<bits/stdc++.h>
using namespace std;
int n,m,s,jo=1,wz[20][20],o,h=1,l=1;
struct point{
	int f;
	int w;
}a[200];
bool cmp(point x,point y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].w=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		wz[h][l]=i;
		if(h%2==1) l++;
		else l--;
		if(l==n+1) l=n,h++;
		if(l==0) l=1,h++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[wz[i][j]].w==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
