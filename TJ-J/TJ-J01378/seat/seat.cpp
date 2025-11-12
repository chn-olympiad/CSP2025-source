#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[105];
bool cmp(int f,int g){
	if(f>g) return f>g;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,n,m,k;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	k = b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1,j=1,x=1;j<=m;x+=0){
		if(j%2!=0){
			while(i<=n){
				a[i][j] = b[x];
				i++;
			}
			if(i>n) j++;x--;
		}
		if(j%2==0){
			i=n;
			while(i>=1){
				a[i][j] = b[x];
				i--;
			}
			if(i<0) i=1;j++;x--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==k) c=j;r=i;
		}
	} 
	cout << c << ' ' << r;
	return 0;
}
