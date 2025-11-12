#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,r;
int a[225];
int b[15][15];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int num;
	int x=1,y=1,up=0;
	for(int i=1;i<=n*m;i++){
		if(x>n||x<1){
			y++;
			if(up==0) x=n;
			else x=1;
			up=1-up;
		}
		if(a[i]==r){
			cout<<y<<' '<<x;
			return 0;
		}
		if(up==0) x++;
		else x--;
	}
	return 0;
}
