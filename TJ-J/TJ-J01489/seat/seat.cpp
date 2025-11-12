#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[1005];
int c[105][105];
int b;
int x1=1;
int z=1;
int l=1;
int r=1;
int cmp(int xx,int yy) {
	return xx>yy;
}
int cop(int x , int y) {
	c[x][y]=a[r];
	r++;
	if(c[x][y]==b) {
		return 0;
	} else if(l%2!=0) {
		if(y<n) {
			y=y+1;
			z++;
		} else {
			x=x+1;
			x1++;
			l++;
		}
		cop(x,y);
	} else {
		if(y>1) {
			y=y-1;
			z--;
		} else {
			x=x+1;
			x1++;
			l++;
		}
		cop(x,y);
	}

}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m*n; i++) {
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+m*n,cmp);
	cop(1,1);
	cout<<x1<<" "<<z;

	return 0;
}
