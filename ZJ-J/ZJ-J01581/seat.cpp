#include <bits/stdc++.h>
using namespace std;
int n,m,r,c,df1;
int a[121];//sorse
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[(i-1)*m+j];
		}
	}
	df1=a[1];
	sort(a+1,a+n*m+1,cmp);
	r=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==df1){
			cout << c << ' ' << r;
			break;
		}
		if(i%n==0){
			c++;
		}
		else{
			if(c%2==1) r++;
			else r--;
		}
	}
	return 0;
}
