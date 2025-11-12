#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
int n,m,a[110],sc,x=0,y=1,k=1;
const int d[]={1,-1};
int f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	For(i,1,n*m) cin>>a[i];
	sc=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	while(k<=n*m){
		x+=d[f];
		if(f==0&&x>n) x=n,++y,f=1;
		if(f==1&&x<1) x=1,++y,f=0;
		if(a[k]==sc) {
			cout<<y<<" "<<x;
			return 0;
		} 
		++k;
	}
	return 0;
}

