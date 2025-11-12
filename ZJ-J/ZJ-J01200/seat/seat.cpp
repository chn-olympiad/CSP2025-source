#include <bits/stdc++.h>
using namespace std;
long long n,m,i,x,y,bao,a[1010],b[20][20];
bool cmp(long long t,long long w){return t>w;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n*m;i++) cin>>a[i];
	bao=a[1];
	sort(a+1,a+1+n*m,cmp);
	y=1;
	for (i=1;i<=n*m;i++){
		if (y%2==1){
			x++;
			if (x>n) y++,x=n;
			b[x][y]=a[i];
		}
		else{
			x--;
			if (x<1) y++,x=1;
			b[x][y]=a[i];
		}
		if (a[i]==bao){cout<<y<<" "<<x;return 0;}
	}
	return 0;
}
