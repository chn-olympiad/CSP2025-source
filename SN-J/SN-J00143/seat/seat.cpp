#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int xr=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cc=0;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cc++;
				if(a[cc]==xr){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				cc++;
				if(a[cc]==xr){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
